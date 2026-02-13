#!/usr/bin/env ruby
# Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
# SPDX-License-Identifier: MIT AND LGPL-2.1


# Users must comply with BOTH MIT AND LGPL-2.1 licenses.

# Configuration manager class
# Licensed under MIT AND LGPL-2.1 (SPDX format)

class ConfigManager
  attr_reader :config

  def initialize
    @config = {}
  end

  # Set a configuration value
  def set(key, value)
    raise ArgumentError, 'Key cannot be nil or empty' if key.nil? || key.to_s.empty?
    @config[key.to_s] = value
  end

  # Get a configuration value
  def get(key, default = nil)
    @config.fetch(key.to_s, default)
  end

  # Check if a key exists
  def has_key?(key)
    @config.key?(key.to_s)
  end

  # Remove a configuration value
  def remove(key)
    @config.delete(key.to_s)
  end

  # Get all configuration keys
  def keys
    @config.keys
  end

  # Get all configuration values
  def values
    @config.values
  end

  # Clear all configuration
  def clear
    @config.clear
  end

  # Get the number of configuration entries
  def size
    @config.size
  end

  # Check if configuration is empty
  def empty?
    @config.empty?
  end

  # Merge another configuration
  def merge(other_config)
    raise ArgumentError, 'Argument must be a Hash' unless other_config.is_a?(Hash)
    @config.merge!(other_config.transform_keys(&:to_s))
  end

  # Export configuration as JSON string
  def to_json
    require 'json'
    @config.to_json
  end

  # Print configuration summary
  def print_summary
    puts "Configuration Summary:"
    puts "-" * 50
    puts "Total entries: #{size}"
    @config.each do |key, value|
      puts "  #{key}: #{value}"
    end
  end
end

# Example usage
if __FILE__ == $PROGRAM_NAME
  config = ConfigManager.new

  # Set some configuration values
  config.set('app_name', 'Qualcomm Test App')
  config.set('version', '1.0.0')
  config.set('debug_mode', true)
  config.set('max_connections', 100)

  # Print summary
  config.print_summary

  # Get specific values
  puts "\nApp Name: #{config.get('app_name')}"
  puts "Debug Mode: #{config.get('debug_mode')}"

  # Check if key exists
  puts "\nHas 'version' key? #{config.has_key?('version')}"
  puts "Has 'unknown' key? #{config.has_key?('unknown')}"

  # Merge additional config
  config.merge({
    'timeout' => 30,
    'retry_count' => 3
  })

  puts "\nAfter merge:"
  config.print_summary
end
