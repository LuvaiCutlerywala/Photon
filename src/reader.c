#include "reader.h"

#include <stdio.h>
#include <stdlib.h>

char* read_file(const char* filename){
  FILE* file = fopen(filename, "r");
  fseek(file, 0, SEEK_END);
  unsigned long file_size = (unsigned long) ftell(file);
  fseek(file, 0, SEEK_SET);
  char* buffer = calloc(file_size, sizeof(char));
  fread(buffer, file_size, 1, file);
  fclose(file);
  return buffer;
}
