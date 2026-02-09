# Copyright (c) 2024 Ruby Developer
# SPDX-License-Identifier: Apache-2.0
#
# This file uses Apache-2.0 license which is COMPATIBLE with BSD-3-Clause.
# This should PASS - Apache-2.0 is a permissive license that's allowed.

class DataValidator
  def initialize
    @errors = []
  end

  def validate_email(email)
    if email.nil? || email.empty?
      @errors << "Email cannot be empty"
      return false
    end
    
    unless email.match?(/\A[\w+\-.]+@[a-z\d\-]+(\.[a-z\d\-]+)*\.[a-z]+\z/i)
      @errors << "Invalid email format"
      return false
    end
    
    true
  end

  def validate_age(age)
    if age.nil?
      @errors << "Age cannot be nil"
      return false
    end
    
    unless age.is_a?(Integer) && age >= 0 && age <= 150
      @errors << "Age must be between 0 and 150"
      return false
    end
    
    true
  end

  def errors
    @errors
  end

  def clear_errors
    @errors = []
  end
end
