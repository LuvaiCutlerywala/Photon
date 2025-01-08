#include "parser.h"

#include <logging/logger.h>
#include <string.h>

PARSER* init_parser(LEXER* lexer) {
  PARSER* parser = calloc(1, sizeof(PARSER));
  parser->lexer = lexer;
  parser->current_token = next_token(lexer);

  return parser;
}

void consume_token(PARSER* parser, const TOKEN_TYPE token_type) {
  if(parser->current_token->type == token_type) {
    parser->current_token = next_token(parser->lexer);
  } else {
    error("parser.consume_token", "Unexpected token.");
    exit(1);
  }
}

AST_NODE* parse(PARSER* parser){
  return parse_statements(parser);
}

AST_NODE* parse_statement(PARSER* parser){
  switch (parser->current_token->type) {
    case TOKEN_IDENTIFIER:
      return parse_identifier(parser);
    case TOKEN_VARIABLE_TYPE:
      return parse_variable_definition(parser);
    case TOKEN_KEYWORD:
        return parse_keyword(parser);
    default:
      debug("parser.parse_statement", "Cannot parse token yet.");
  }

  return NULL;
}

AST_NODE* parse_statements(PARSER* parser){
  AST_NODE* compound = init_ast_node(AST_COMPOUND);
  compound->compound = calloc(1, sizeof(AST_NODE*));
  AST_NODE* statement = parse_statement(parser);
  compound->compound[0] = statement;

  while(parser->current_token->type == TOKEN_SEMICOLON) {
    consume_token(parser, TOKEN_SEMICOLON);
    statement = parse_statement(parser);
    compound->compound_size++;
    compound->compound = realloc(compound->compound, compound->compound_size * sizeof(AST_NODE*));
    compound->compound[compound->compound_size - 1] = statement;
  }

  return compound;
}

AST_NODE* parse_expression(PARSER* parser){
  return NULL;
}

AST_NODE* parse_factor(PARSER* parser){
  return NULL;
}

AST_NODE* parse_term(PARSER* parser){
  return NULL;
}

AST_NODE* parse_function_call(PARSER* parser){
  return NULL;
}

AST_NODE* parse_variable_definition(PARSER* parser) {
  consume_token(parser, TOKEN_VARIABLE_TYPE);
  char* variable_name = parser->current_token->value;
  consume_token(parser, TOKEN_IDENTIFIER);
  consume_token(parser, TOKEN_ASSIGN);
  AST_NODE* variable_value = parse_expression(parser);
  AST_NODE* variable_definition = init_ast_node(AST_VARIABLE_DEFINITION);
  variable_definition->variable_defined_name = variable_name;
  variable_definition->variable_definition = variable_value;
  return variable_definition;
}

AST_NODE* parse_string(PARSER* parser){
  return NULL;
}

AST_NODE* parse_keyword(PARSER* parser) {
  return NULL;
}

AST_NODE* parse_identifier(PARSER* parser) {
  char* token_value = parser->current_token->value;
  consume_token(parser, TOKEN_IDENTIFIER);
  if (parser->current_token->type == TOKEN_LEFT_PARENTHESIS) {
    return parse_function_call(parser);
  }

  AST_NODE* variable = init_ast_node(AST_VARIABLE);
  variable->variable_name = token_value;

  return variable;
}
