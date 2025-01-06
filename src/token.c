#include "include/token.h"

#include <stdlib.h>

TOKEN* init_token(TOKEN_TYPE type, char* value){
  TOKEN* token = calloc(1, sizeof(TOKEN));
  token->type = type;
  token->value = value;

  return token;
}
