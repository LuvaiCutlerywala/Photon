#ifndef TOKEN_H
#define TOKEN_H

/*
 * The list of possible keywords. As of now, due to the in-development state of the language, there aren't that many.
 * Once the base language has been developed, more keywords can be added as required.
 */
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

/*
 * The list of possible primitive types. Currently, arrays are not a supported type, however they will soon be added.
 * The core types are already present, and most likely, other types, when added, will follow the C language types, as
 * they will be an optional part of the standard library.
 */
const static char* TYPES[5] = {
  "string",
  "int",
  "real",
  "boolean",
  "byte"
};

/*
 * The types of tokens that the lexer can recognise and generate. As the language is currently in development, the core
 * tokens are present, but once the base language has been completed, more sophisticated grammar can be added, in the
 * form of lambda expressions, syntactic sugar, etc.
 */
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

/*
 * The structure of a token. All tokens only have a string value, as the actual strings are parsed into their correct
 * underlying types either during the syntax analysis stage, or the code generation stage.
 */
typedef struct token {
  TOKEN_TYPE type;
  char* value;
} TOKEN;

/// @brief  Initialises the token.
/// @param  type The token type.
/// @param  value The token value.
TOKEN* init_token(TOKEN_TYPE type, char* value);

#endif
