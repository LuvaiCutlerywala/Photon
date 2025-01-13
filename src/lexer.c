#include "include/lexer.h"
#include "include/macros.h"

#include <logging/logger.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

//Helper Methods

char* wrap_char_to_str(const char c){
  char* string = calloc(2, sizeof(char));
  string[0] = c;
  string[1] = '\0';
  return string;
}

bool instance_of(const char* word, const char** list) {
  for (unsigned long i = 0; i < SIZE(list); i++) {
    if (strcmp(word, list[i]) == 0) {
      return true;
    }
  }
  return false;
}

//Lexer State Modifiers

LEXER* init_lexer(char* content) {
  LEXER* lexer = calloc(1, sizeof(LEXER));
  lexer->content = content;
  lexer->current_index = 0;
  lexer->current_char = lexer->content[lexer->current_index];
  return lexer;
}

void advance(LEXER* lexer) {
  if (lexer->content[lexer->current_index] != '\0' && lexer->current_index < strlen(lexer->content)) {
    lexer->current_index++;
    lexer->current_char = lexer->content[lexer->current_index];
  }
}

void skip_whitespace_newline(LEXER* lexer) {
  while (lexer->content[lexer->current_index] == ' ' || lexer->content[lexer->current_index] == '\n') {
    advance(lexer);
  }
}

void strip_comments(LEXER* lexer) {
  //Skips the two front slashes required to make a comment.
  advance(lexer);
  advance(lexer);
  while (lexer->current_char != '\n' && lexer->current_char != '\0') {
    advance(lexer);
  }
  advance(lexer);
}

// Tokenization method

TOKEN* next_token(LEXER* lexer) {
  while (lexer->current_char != '\0' || lexer->current_index < strlen(lexer->content)) {
    if (lexer->current_char == '\n' || lexer->current_char == ' ') {
      skip_whitespace_newline(lexer);
    }

    if (lexer->current_char == '"') {
      return tokenize_string(lexer);
    }

    if (isdigit(lexer->current_char)) {
      return tokenize_number(lexer);
    }

    if (isalnum(lexer->current_char)) {
      return tokenize_identifier(lexer);
    }

    if ((lexer->current_index + 1 < strlen(lexer->content))
      && (lexer->current_char == '/' && lexer->content[lexer->current_index + 1] == '/')){
        strip_comments(lexer);
      }

    switch (lexer->current_char) {
      case '(':
        return tokenize(lexer, TOKEN_LEFT_PARENTHESIS);
      case ')':
        return tokenize(lexer, TOKEN_RIGHT_PARENTHESIS);
      case ';':
        return tokenize(lexer, TOKEN_SEMICOLON);
      case '=':
        return tokenize(lexer, TOKEN_ASSIGN);
      case '+':
        return tokenize(lexer, TOKEN_PLUS);
      case '-':
        return tokenize(lexer, TOKEN_MINUS);
      case '*':
        return tokenize(lexer, TOKEN_STAR);
      case '/':
        return tokenize(lexer, TOKEN_SLASH);
      case '{':
        return tokenize(lexer, TOKEN_LEFT_BRACE);
      case '}':
        return tokenize(lexer, TOKEN_RIGHT_BRACE);
      case ',':
        return tokenize(lexer, TOKEN_COMMA);
      default:
        error("lexer.next_token", "Invalid character");
    }
  }

  return NULL;
}

TOKEN* tokenize(LEXER* lexer, const TOKEN_TYPE type) {
  TOKEN* token = init_token(type, wrap_char_to_str(lexer->current_char));
  advance(lexer);
  return token;
}

TOKEN* tokenize_number(LEXER* lexer) {
  char* number = calloc(1, sizeof(char));
  number[0] = '\0';
  bool is_real = false;
  while (isdigit(lexer->current_char) || lexer->current_char == '.') {
    if (lexer->current_char == '.' && !is_real) {
      is_real = true;
    }
    char* new_str = wrap_char_to_str(lexer->current_char);
    number = realloc(number, (strlen(number) + strlen(new_str) + 1) * sizeof(char));
    strcat(number, new_str);
    free(new_str);
    advance(lexer);
  }

  advance(lexer);

  if (number == NULL) {
    error("lexer.tokenize_number", "Failed to parse number.");
    exit(1);
  }

  return (is_real) ? init_token(TOKEN_REAL_LITERAL, number) : init_token(TOKEN_INTEGER_LITERAL, number);
}

TOKEN* tokenize_identifier(LEXER* lexer) {
  char* id = calloc(1, sizeof(char));
  id[0] = '\0';
  while (isalnum(lexer->current_char)) {
    char* new_str = wrap_char_to_str(lexer->current_char);
    id = realloc(id, (strlen(id) + strlen(new_str) + 1) * sizeof(char));
    strcat(id, new_str);
    free(new_str);
    advance(lexer);
  }

  if (id == NULL) {
    error("lexer.collect_identifier", "Failed to parse identifier.");
    exit(1);
  }

  if (instance_of(id, KEYWORDS)) {
    return init_token(TOKEN_KEYWORD, id);
  }
  if (instance_of(id, TYPES)) {
    return init_token(TOKEN_VARIABLE_TYPE, id);
  }

  return init_token(TOKEN_IDENTIFIER, id);
}

TOKEN* tokenize_string(LEXER* lexer) {
  advance(lexer);
  char* string = calloc(1, sizeof(char));
  string[0] = '\0';
  while (lexer->current_char != '"') {
    char* new_str = wrap_char_to_str(lexer->current_char);
    string = realloc(string, (strlen(string) + strlen(new_str) + 1) * sizeof(char));
    strcat(string, new_str);
    free(new_str);
    advance(lexer);
  }

  advance(lexer);

  if (string == NULL) {
    error("lexer.collect_string", "Failed to parse string.");
    exit(1);
  }

  return init_token(TOKEN_STRING_LITERAL, string);
}
