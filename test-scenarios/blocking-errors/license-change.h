/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef UTILS_H
#define UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Calculate the maximum of two integers
 */
int max(int a, int b);

/**
 * Calculate the minimum of two integers
 */
int min(int a, int b);

/**
 * Check if a number is even
 */
int is_even(int n);

#ifdef __cplusplus
}
#endif

#endif /* UTILS_H */
