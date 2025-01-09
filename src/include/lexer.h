#ifndef LEXER_H
#define LEXER_H

#include "token.h"

#include <stdbool.h>

/*
 * Stores the state of the lexer, as a makeshift object.
 */
typedef struct lexer {
  unsigned int current_index;
  char current_char;
  char* content;
} LEXER;

//Lexer state modifiers.

/// @brief Initialises the lexer.
/// @param content The content that the lexer will be tokenizing.
LEXER* init_lexer(char* content);

/// @brief Advances the lexer to the next character.
/// @param lexer The lexer state.
void advance(LEXER* lexer);

/// @brief Skips whitespace and newline characters.
/// @param lexer The lexer state.
void skip_whitespace_newline(LEXER* lexer);

/// @brief Strips the comments from the contents to be parsed.
/// @param lexer The lexer state.
void strip_comments(LEXER* lexer);

//Tokenization methods.

/// @brief Fetches the next token from the lexer contents.
/// @param lexer The lexer state.
TOKEN* next_token(LEXER* lexer);

/// @brief Tokenizes the current character in the lexer, along with its token type.
/// @param lexer The lexer state.
/// @param type The type of the token generated for the character.
TOKEN* tokenize(LEXER* lexer, TOKEN_TYPE type);

/// @brief Tokenizes the next number that the lexer encounters. Works with both real and integral numbers.
/// @param lexer The lexer state.
TOKEN* tokenize_number(LEXER* lexer);

/// @brief Tokenizes the next identifier that the lexer encounters. Identifiers include both function and variable
/// names.
/// @param lexer The lexer state.
TOKEN* tokenize_identifier(LEXER* lexer);

/// @brief Tokenizes the next string that the lexer encounters.
/// @param lexer The lexer state.
TOKEN* tokenize_string(LEXER* lexer);

//Helper Methods

/// @brief Wraps a single character into a string.
/// @param c The character to be wrapped.
char* wrap_char_to_str(char c);

/// @brief Checks if a given word is present in the list. Used for checking for keywords or primitive types.
/// @param word The word to be checked.
/// @param list The collection of possible instance types.
bool instance_of(const char* word, const char** list);

#endif
