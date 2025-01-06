#include "logger.h"

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print(FILE* stream, char* mode, char* message, char* source) {
  const time_t current_time = time(NULL);
  const char* ctime_timestamp = ctime(&current_time);
  char* timestamp = malloc(sizeof(char) * (strlen(ctime_timestamp) - 2));
  memcpy(timestamp, ctime_timestamp, strlen(ctime_timestamp) - 2);
  fprintf(stream, "[%s] [%s] AT [%s]: %s\n", mode, timestamp, source, message);
  free(timestamp);
}

void info(char* source, char* message){
  print(stdout, "INFO", message, source);
}

void error(char* source, char* message){
  print(stderr, "ERROR", message, source);
}

void warn(char* source, char* message){
  print(stderr, "WARN", message, source);
}

void debug(char* source, char* message){
  print(stdout, "DEBUG", message, source);
}
