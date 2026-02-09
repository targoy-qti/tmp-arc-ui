/*
 * Copyright (c) 2024 Freeware Developer
 * 
 * FREEWARE LICENSE
 * 
 * This software is provided as freeware for personal and educational use only.
 * You may use this software free of charge, but you may not sell, rent, lease,
 * or otherwise transfer this software to third parties for profit.
 * 
 * NO WARRANTY: This software is provided "as is" without warranty of any kind,
 * either expressed or implied, including but not limited to the implied warranties
 * of merchantability and fitness for a particular purpose.
 * 
 * This is a custom freeware license that scancode will identify as unknown.
 */


import Foundation

class Calculator {
    func add(_ a: Int, _ b: Int) -> Int {
        return a + b
    }
    
    func subtract(_ a: Int, _ b: Int) -> Int {
        return a - b
    }
    
    func multiply(_ a: Int, _ b: Int) -> Int {
        return a * b
    }
    
    func divide(_ a: Int, _ b: Int) -> Int? {
        guard b != 0 else { return nil }
        return a / b
    }
}

let calc = Calculator()
print("5 + 3 = \(calc.add(5, 3))")
print("5 * 3 = \(calc.multiply(5, 3))")
