#ifndef READER_H
#define READER_H

#include <stdbool.h>

/// @brief Reads the contents of the file into one large character buffer.
/// @param filename The relative path of the file.
char* read_file(const char* filename);

/// @brief Reads the file name, and determines whether the type for the interpreter is correct.
/// @param filename The filename.
bool verify_file_type(const char* filename);

#endif
