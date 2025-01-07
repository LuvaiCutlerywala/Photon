#ifndef LEXER_H
#define LEXER_H

#include "token.h"

#include <stdbool.h>

typedef struct lexer {
  unsigned int current_index;
  char current_char;
  char* content;
} LEXER;

//Lexer state modifiers.
LEXER* init_lexer(char* content);
void advance(LEXER* lexer);
void skip_whitespace_newline(LEXER* lexer);
void strip_comments(LEXER* lexer);

//Tokenization method.
TOKEN* next_token(LEXER* lexer);
TOKEN* tokenize(LEXER* lexer, TOKEN_TYPE type);
TOKEN* tokenize_number(LEXER* lexer);
TOKEN* tokenize_identifier(LEXER* lexer);
TOKEN* tokenize_string(LEXER* lexer);

//Helper Methods
char* wrap_char_to_str(const char* c);
bool instance_of(const char* word, const char** list);

#endif
