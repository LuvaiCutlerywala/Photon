#ifndef MACROS_H
#define MACROS_H

#include <stdlib.h>

/*
 * Gets the size of the array.
 */
#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

/// @brief Wraps a single character into a string.
/// @param character The character to be wrapped.
char* wrap_as_str(const char character);

#endif
