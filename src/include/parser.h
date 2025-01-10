#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "AST.h"

/*
 * A struct that represents the parser state. Lexical analysis, in this compiler, is done dynamically, as it allows a
 * greater flexibility and the use of recursive tree generation algorithms in the syntax analysis stage, when generating
 * the abstract syntax tree. Therefore, the parser encapsulates the lexer, and dynamically loads and parses tokens.
 */
typedef struct parser {
  LEXER* lexer;
  TOKEN* current_token;
  TOKEN* prev_token;
} PARSER;

//Parser State Modifier

/// @brief  Initialises the parser.
/// @param lexer The lexer that the parser encapsulates.
PARSER* init_parser(LEXER* lexer);

/// @brief Consumes the current token, i.e. checks if the current token type is the same as the expected type, and then
/// advances the lexer. If the token type is not expected, kills the compiler.
/// @param parser The parser which consumes the token.
/// @param token_type The expected token type.
void consume_token(PARSER* parser, TOKEN_TYPE token_type);

//Parsing Methods

/// @brief Parses the content that was used to initialise the lexer.
/// @param parser The parser to begin the syntax analysis.
AST_NODE* parse(PARSER* parser);

/// @brief Parses a single statement. A statement is defined as one single line, delimited by semicolons.
/// @param parser The parser.
AST_NODE* parse_statement(PARSER* parser);

/// @brief Parses a group of statements. Can be used to parse a code block of arbitrary size, whether it is the whole
/// codebase or a code block inside a control flow statement.
/// @param parser The parser.
AST_NODE* parse_statements(PARSER* parser);

/// @brief Parses an expression. Any collection of logical operations, that results in an output is defined as an
/// expression.
/// @param parser The parser.
AST_NODE* parse_expression(PARSER* parser);

/// @brief Parses a factor. Any sub-expression, which involves a logical multiplicative step, i.e. an action of a group,
/// can be taken to be a factor. For any closed set which forms a group, the factors of an element can be defined as two
/// other elements which, when used with the group operation, result in the former element, with the arity of the
/// multiplicative operation being 2.
/// @param parser The parser.
AST_NODE* parse_factor(PARSER* parser);

/// @brief Parses a term. For any sub-expression that is formed by the use of logical addition, i.e. union, of 2 or more
/// elements that are within the group, the elements used to form the other elements are called terms.
/// @param parser The parser.
AST_NODE* parse_term(PARSER* parser);

/// @brief Parses a function call. Generates an AST node with the metadata required to call back to a function.
/// @param parser The parser.
AST_NODE* parse_function_call(PARSER* parser);

/// @brief Parses a variable definition. Currently, only literal definitions are supported, but once factor and term
/// parsing is properly implemented, expressions that are assigned to variables will also be parsed correctly.
/// @param parser The parser.
AST_NODE* parse_variable_definition(PARSER* parser);

/// @brief Parses a string.
/// @param parser The parser.
AST_NODE* parse_string(PARSER* parser);

/// @brief Parses keywords. Some keywords are single instructions, other keywords are used to denote control flow blocks
/// with different paths depending on the evaluation of some condition.
/// @param parser The parser.
AST_NODE* parse_keyword(PARSER* parser);

/// @brief Parses identifiers. Identifiers include function names and variable names.
/// @param parser The parser.
AST_NODE* parse_identifier(PARSER* parser);

#endif
