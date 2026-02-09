#!/bin/bash
# Copyright (c) 2024 Proprietary Software Inc.
# 
# PROPRIETARY AND CONFIDENTIAL
# 
# This software and associated documentation files are the proprietary
# property of Proprietary Software Inc. All rights reserved.
# 
# LICENSE TERMS:
# 1. This software is licensed, not sold.
# 2. You may not reverse engineer, decompile, or disassemble this software.
# 3. You may not rent, lease, or lend this software.
# 4. This software may not be copied or distributed without written permission.
# 5. Unauthorized use, copying, or distribution is strictly prohibited.
# 
# RESTRICTIONS: This software contains trade secrets and proprietary information.
# Any unauthorized disclosure or use may result in legal action.
# 
# This is a custom proprietary license that scancode will identify as unknown.

# Simple backup script
backup_directory() {
    local source_dir="$1"
    local backup_dir="$2"
    local timestamp=$(date +%Y%m%d_%H%M%S)
    
    if [ ! -d "$source_dir" ]; then
        echo "Error: Source directory does not exist: $source_dir"
        return 1
    fi
    
    mkdir -p "$backup_dir"
    
    local backup_file="${backup_dir}/backup_${timestamp}.tar.gz"
    tar -czf "$backup_file" -C "$(dirname "$source_dir")" "$(basename "$source_dir")"
    
    if [ $? -eq 0 ]; then
        echo "Backup created successfully: $backup_file"
        return 0
    else
        echo "Error: Backup failed"
        return 1
    fi
}

# Example usage
# backup_directory "/path/to/source" "/path/to/backups"
