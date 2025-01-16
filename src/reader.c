#include "reader.h"

#include <macros.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <logging/logger.h>

char* read_file(const char* filename){
  if (!verify_file_type(filename)) {
    error("reader.read_file", "Unrecognised source type used.");
    exit(1);
  }
  FILE* file = fopen(filename, "r");
  fseek(file, 0, SEEK_END);
  unsigned long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);
  char* buffer = calloc(file_size, sizeof(char));
  fread(buffer, file_size, 1, file);
  fclose(file);
  return buffer;
}

bool verify_file_type(const char* filename) {
  //Copy the file extension.
  char* buffer = calloc(1, sizeof(char));
  buffer[0] = '\0';
  int ext_size = 0;
  while (filename[strlen(filename) - (ext_size + 1)] != '.') {
    char* new_str = wrap_as_str(filename[strlen(filename) - (ext_size + 1)]);
    buffer = realloc(buffer, (strlen(buffer) + strlen(new_str) + 1) * sizeof(char));
    strcat(buffer, new_str);
    free(new_str);
    ext_size++;
  }

  //Reverse the buffer order.
  int i = strlen(buffer) - 1;
  int j = 0;
  while(i > j)
  {
    char temp = buffer[i];
    buffer[i] = buffer[j];
    buffer[j] = temp;
    i--;
    j++;
  }

  if (ext_size > 3 ||strcmp(buffer, "pht") != 0) {
    return false;
  }

  return true;
}
