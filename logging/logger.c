#include "logger.h"

#include <time.h>
#include <string.h>
#include <stdlib.h>

char* get_timestamp() {
  const time_t current_time = time(NULL);
  const char* ctime_timestamp = ctime(&current_time);
  char* timestamp = malloc(sizeof(char)* (strlen(ctime_timestamp) - 2));
  memcpy(timestamp, ctime_timestamp, strlen(ctime_timestamp));
  return timestamp;
}

void print(FILE* stream, char* mode, char* message, char* source) {
  char* timestamp = get_timestamp();
  fprintf(stream, "[%s] [%s] AT [%s]: %s\n", mode, timestamp, source, message);
  free(timestamp);
}

void print(FILE* stream, char* mode, int value, char* source) {
  char* timestamp = get_timestamp();
  fprintf(stream, "[%s] [%s] AT [%s]: %d\n", mode, timestamp, source, value);
  free(timestamp);
}

void info(char* source, char* message){
  print(stdout, "INFO", message, source);
}

void info(char* source, int value) {
  print(stdout, "INFO", value, source);
}

void error(char* source, char* message){
  print(stderr, "ERROR", message, source);
}

void error(char* source, int value) {
  print(stderr, "ERROR", value, source);
}

void warn(char* source, char* message){
  print(stderr, "WARN", message, source);
}

void warn(char* source, int value) {
  print(stderr, "WARN", value, source);
}

void debug(char* source, char* message){
  print(stdout, "DEBUG", message, source);
}

void debug(char* source, int value) {
  print(stdout, "DEBUG", value, source);
}
