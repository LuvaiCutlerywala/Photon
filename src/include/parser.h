#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "AST.h"

typedef struct parser {
  LEXER* lexer;
  TOKEN* current_token;
} PARSER;

//Parser State Modifier
PARSER* init_parser(LEXER* lexer);
void consume_token(PARSER* parser, TOKEN_TYPE token_type);

//Parsing Methods
AST_NODE* parse(PARSER* parser);
AST_NODE* parse_statement(PARSER* parser);
AST_NODE* parse_statements(PARSER* parser);
AST_NODE* parse_expression(PARSER* parser);
AST_NODE* parse_factor(PARSER* parser);
AST_NODE* parse_term(PARSER* parser);
AST_NODE* parse_function_call(PARSER* parser);
AST_NODE* parse_variable_definition(PARSER* parser);
AST_NODE* parse_string(PARSER* parser);
AST_NODE* parse_keyword(PARSER* parser);
AST_NODE* parse_identifier(PARSER* parser);

#endif
