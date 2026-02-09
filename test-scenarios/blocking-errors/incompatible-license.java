/*
 * Copyright (c) 2024 Some Developer
 * SPDX-License-Identifier: GPL-3.0-only
 */

public class DataProcessor {
    
    public static String processData(String input) {
        if (input == null || input.isEmpty()) {
            return "";
        }
        return input.toUpperCase().trim();
    }
    
    public static int countWords(String text) {
        if (text == null || text.isEmpty()) {
            return 0;
        }
        return text.split("\\s+").length;
    }
    
    public static void main(String[] args) {
        String sample = "Hello World";
        System.out.println("Processed: " + processData(sample));
        System.out.println("Word count: " + countWords(sample));
    }
}
