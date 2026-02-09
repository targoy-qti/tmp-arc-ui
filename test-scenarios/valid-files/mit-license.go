/*
 * Copyright (c) 2024 Developer Name
 * SPDX-License-Identifier: MIT
 * 
 * This file uses MIT license which is COMPATIBLE with BSD-3-Clause.
 * This should PASS - MIT is a permissive license that's allowed.
 */

package main

import (
	"fmt"
	"strings"
)

// StringUtils provides utility functions for string manipulation
type StringUtils struct{}

// Reverse reverses a string
func (s *StringUtils) Reverse(input string) string {
	runes := []rune(input)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// ToTitle converts string to title case
func (s *StringUtils) ToTitle(input string) string {
	return strings.Title(strings.ToLower(input))
}

func main() {
	utils := &StringUtils{}
	text := "hello world"
	fmt.Println("Original:", text)
	fmt.Println("Reversed:", utils.Reverse(text))
	fmt.Println("Title:", utils.ToTitle(text))
}
