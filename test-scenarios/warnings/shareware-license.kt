/*
 * Copyright (c) 2024 Shareware Author
 * 
 * SHAREWARE LICENSE AGREEMENT
 * 
 * This is shareware software. You may try this software for a 30-day evaluation
 * period. After the evaluation period, you must either register the software by
 * paying the registration fee or discontinue use.
 * 
 * TRIAL VERSION LIMITATIONS:
 * - Limited to 30 days of use
 * - Some features may be disabled
 * - Registration required for continued use
 * 
 * DISTRIBUTION: You may freely distribute the unregistered version of this
 * software, provided that no fee is charged and the software is not modified.
 * 
 * This is a custom shareware license that scancode will identify as unknown.
 */

package com.example.utils

class StringHelper {
    fun reverse(input: String): String {
        return input.reversed()
    }
    
    fun capitalize(input: String): String {
        return input.replaceFirstChar { 
            if (it.isLowerCase()) it.titlecase() else it.toString() 
        }
    }
    
    fun countWords(input: String): Int {
        return input.trim().split("\\s+".toRegex()).size
    }
}

fun main() {
    val helper = StringHelper()
    val text = "hello world"
    
    println("Original: $text")
    println("Reversed: ${helper.reverse(text)}")
    println("Capitalized: ${helper.capitalize(text)}")
    println("Word count: ${helper.countWords(text)}")
}
