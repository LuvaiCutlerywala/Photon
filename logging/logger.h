#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

/// @brief Returns the current time, formatted into a ctime timestamp.
char* get_timestamp(void);

/// @brief Prints a string message to the designated output.
/// @param stream The designated output.
/// @param mode The logging mode. Can be either info, warn, error, or debug.
/// @param message The string message to be logged.
/// @param source The location where the log originates.
void print_str(FILE* stream, char* mode, char* message, char* source);

/// @brief Prints an integer to the designated output.
/// @param stream The designated output.
/// @param mode The logging mode. Can be either info, warn, error, or debug.
/// @param value The integer value to be logged.
/// @param source The location where the log originates.
void print_int(FILE* stream, char* mode, int value, char* source);

/// @brief Logs a piece of information to the standard output.
/// @param source The location where the log originates.
/// @param message The message to be logged.
void info(char* source, char* message);

/// @brief Logs an integral piece of information to the standard output.
/// @param source The location where the log originates.
/// @param value The integral value to be logged.
void info_int(char* source, int value);

/// @brief Logs an error to the standard error output.
/// @param source The location where the log originates.
/// @param message The message to be logged.
void error(char* source, char* message);

/// @brief Logs an integral error to the standard error output.
/// @param source The location where the log originates.
/// @param value The integral value to be logged.
void error_int(char* source, int value);

/// @brief Logs a warning to the standard error output.
/// @param source The location where the log originates.
/// @param message The message to be logged.
void warn(char* source, char* message);

/// @brief Logs an integral warning to the standard error output.
/// @param source The location where the log originates.
/// @param value The integral value to be logged.
void warn_int(char* source, int value);

/// @brief Logs a piece of debugging information to the standard output.
/// @param source The location where the log originates.
/// @param message The message to be logged.
void debug(char* source, char* message);

/// @brief Logs an integral piece of debugging information to the standard output.
/// @param source The location where the log originates.
/// @param value The integral value to be logged.
void debug_int(char* source, int value);


#endif
