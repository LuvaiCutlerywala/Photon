#include "logger.h"

#include <time.h>
#include <string.h>
#include <stdlib.h>

char* get_timestamp() {
  const time_t current_time = time(NULL);
  char* timestamp = ctime(&current_time);
  timestamp[strlen(timestamp) - 1] = '\0';
  return timestamp;
}

void print_str(FILE* stream, char* mode, char* message, char* source) {
  fprintf(stream, "[%s] [%s] AT [%s]: %s\n", mode, get_timestamp(), source, message);
}

void print_int(FILE* stream, char* mode, int value, char* source) {
  fprintf(stream, "[%s] [%s] AT [%s]: %d\n", mode, get_timestamp(), source, value);
}

void info(char* source, char* message){
  print_str(stdout, "INFO", message, source);
}

void info_int(char* source, int value) {
  print_int(stdout, "INFO", value, source);
}

void error(char* source, char* message){
  print_str(stderr, "ERROR", message, source);
}

void error_int(char* source, int value) {
  print_int(stderr, "ERROR", value, source);
}

void warn(char* source, char* message){
  print_str(stderr, "WARN", message, source);
}

void warn_int(char* source, int value) {
  print_int(stderr, "WARN", value, source);
}

void debug(char* source, char* message){
  print_str(stdout, "DEBUG", message, source);
}

void debug_int(char* source, int value) {
  print_int(stdout, "DEBUG", value, source);
}
