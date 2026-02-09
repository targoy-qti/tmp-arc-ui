#!/usr/bin/env python3
# Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
# SPDX-License-Identifier: BSD-3-Clause

"""
This is a properly licensed Python file with correct copyright and license headers.
This should PASS the copyright-license-checker without any issues.
"""


def calculate_sum(a: int, b: int) -> int:
    """Calculate the sum of two numbers."""
    return a + b


def main():
    """Main function."""
    result = calculate_sum(5, 10)
    print(f"Result: {result}")


if __name__ == "__main__":
    main()
