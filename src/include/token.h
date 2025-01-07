#ifndef TOKEN_H
#define TOKEN_H

const static char* KEYWORDS[9] = {
  "if",
  "while",
  "for",
  "break",
  "continue",
  "else",
  "return",
  "true",
  "false"
};

const static char* TYPES[5] = {
  "string",
  "int",
  "real",
  "boolean",
  "byte"
};

typedef enum token_type {
  //Identifiers
  TOKEN_KEYWORD,
  TOKEN_VARIABLE_TYPE,
  TOKEN_IDENTIFIER,

  //Type literals
  TOKEN_INTEGER_LITERAL,
  TOKEN_STRING_LITERAL,
  TOKEN_REAL_LITERAL,
  TOKEN_BYTE_LITERAL,

  //Special Characters
  TOKEN_LEFT_PARENTHESIS,
  TOKEN_RIGHT_PARENTHESIS,
  TOKEN_SEMICOLON,
  TOKEN_COMMA,
  TOKEN_ASSIGN,
  TOKEN_PLUS,
  TOKEN_MINUS,
  TOKEN_STAR,
  TOKEN_SLASH,
  TOKEN_LEFT_BRACE,
  TOKEN_RIGHT_BRACE
} TOKEN_TYPE;

typedef struct token {
  TOKEN_TYPE type;
  char* value;
} TOKEN;

TOKEN* init_token(TOKEN_TYPE type, char* value);

#endif
