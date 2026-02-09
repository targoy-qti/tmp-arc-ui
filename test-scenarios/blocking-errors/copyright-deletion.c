/*
 * Copyright (c) Tarun
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * 
 * Original copyright that should NOT be removed:
 * Copyright (c) 2023 Original Developer
 */

#include <stdio.h>
#include <string.h>

int string_length(const char* str) {
    if (str == NULL) {
        return 0;
    }
    return strlen(str);
}

void print_message(const char* message) {
    printf("Message: %s\n", message);
}

int main() {
    const char* text = "Hello, World!";
    printf("Length: %d\n", string_length(text));
    print_message(text);
    return 0;
}
