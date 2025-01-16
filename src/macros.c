#include "include/macros.h"

char* wrap_as_str(const char character){
    char* string = calloc(2, sizeof(char));
    string[0] = character;
    string[1] = '\0';
    return string;
}
