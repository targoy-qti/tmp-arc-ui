/*
 * Copyright (c) 2023 Original Author
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * This file demonstrates proper handling of multiple copyright holders.
 * This should PASS - multiple copyrights are allowed and encouraged.
 */

#include <iostream>
#include <string>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    
    int multiply(int a, int b) {
        return a * b;
    }
};

int main() {
    Calculator calc;
    std::cout << "5 + 3 = " << calc.add(5, 3) << std::endl;
    std::cout << "5 * 3 = " << calc.multiply(5, 3) << std::endl;
    return 0;
}
