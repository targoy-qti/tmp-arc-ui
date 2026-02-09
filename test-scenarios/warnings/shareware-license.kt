/*
 * Copyright (c) 2024 Change Author
 * Copyright (c) 2023 ThirdParty Software Inc. - All Rights Reserved
 * 
 * PROPRIETARY AND CONFIDENTIAL
 * 
 * This software contains proprietary information belonging to ThirdParty Software Inc.
 * Unauthorized copying, distribution, or use of this software is strictly prohibited.
 * 
 * THIRD PARTY COMPONENTS:
 * This software includes proprietary components from ThirdParty Software Inc.
 * which are subject to separate license terms and restrictions..
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
