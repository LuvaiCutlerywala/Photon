#include "include/lexer.h"

#include <logging/logger.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

//Helper Methods

char* wrap_char_to_str(const char c) {
  char* string = calloc(2, sizeof(char));
  string[0] = c;
  string[1] = '\0';
  return string;
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

// Tokenization method

TOKEN* next_token(LEXER* lexer) {
  //TODO: Complete tokenization method.
  while (lexer->current_char != '\0' || lexer->current_index < strlen(lexer->content)) {
    if (lexer->current_char == '\n' || lexer->current_char == ' ') {
      debug("lexer.next_token", "Skipping spaces and newlines.");
      skip_whitespace_newline(lexer);
    }

    if (lexer->current_char == '"') {
      debug("lexer.next_token", "Parsing strings.");
      return init_token(TOKEN_STRING_LITERAL, collect_string(lexer));
    }

    if (isdigit(lexer->current_char)) {
      debug("lexer.next_token", "Parsing number.");
      return tokenize_number(lexer);
    }

    if (isalnum(lexer->current_char)) {
      debug("lexer.next_token", "Parsing identifiers.");
      return init_token(TOKEN_IDENTIFIER, collect_identifier(lexer));
    }

    switch (lexer->current_char) {
      case '(':
        debug("lexer.next_token", "Parsing left parenthesis.");
        return tokenize(lexer, TOKEN_LEFT_PARENTHESIS);
      case ')':
        debug("lexer.next_token", "Parsing right parenthesis.");
        return tokenize(lexer, TOKEN_RIGHT_PARENTHESIS);
      case ';':
        debug("lexer.next_token", "Parsing semicolon.");
        return tokenize(lexer, TOKEN_SEMICOLON);
      case '=':
        debug("lexer.next_token", "Parsing equals sign.");
        return tokenize(lexer, TOKEN_ASSIGN);
      case '+':
        debug("lexer.next_token", "Parsing plus.");
        return tokenize(lexer, TOKEN_PLUS);
      case '-':
        debug("lexer.next_token", "Parsing minus.");
      return tokenize(lexer, TOKEN_MINUS);
      case '*':
        debug("lexer.next_token", "Parsing star.");
      return tokenize(lexer, TOKEN_STAR);
      case '/':
        debug("lexer.next_token", "Parsing slash.");
      return tokenize(lexer, TOKEN_SLASH);
      case '{':
        debug("lexer.next_token", "Parsing brackets.");
        return tokenize(lexer, TOKEN_LEFT_BRACE);
      case '}':
        debug("lexer.next_token", "Parsing brackets.");
        return tokenize(lexer, TOKEN_RIGHT_BRACE);
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

  TOKEN* token = (is_real) ? init_token(TOKEN_REAL_LITERAL, number) : init_token(TOKEN_INTEGER_LITERAL, number);

  return token;
}

//Collection methods

char* collect_string(LEXER* lexer) {
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

  return string;
}

char* collect_identifier(LEXER* lexer) {
  char* id = calloc(1, sizeof(char));
  id[0] = '\0';
  while (isalnum(lexer->current_char)) {
    char* new_str = wrap_char_to_str(lexer->current_char);
    id = realloc(id, (strlen(id) + strlen(new_str) + 1) * sizeof(char));
    strcat(id, new_str);
    free(new_str);
    advance(lexer);
  }

  advance(lexer);

  if (id == NULL) {
    error("lexer.collect_identifier", "Failed to parse identifier.");
    exit(1);
  }

  return id;
}
