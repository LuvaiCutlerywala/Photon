#include "parser.h"

#include <logging/logger.h>
#include <string.h>

PARSER* init_parser(LEXER* lexer) {
  PARSER* parser = calloc(1, sizeof(PARSER));
  parser->lexer = lexer;
  parser->current_token = next_token(lexer);
  parser->prev_token = NULL;

  return parser;
}

void consume_token(PARSER* parser, const TOKEN_TYPE token_type) {
  if(parser->current_token->type == token_type) {
    parser->prev_token = parser->current_token;
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
  //TODO: Complete method to parse statements.
  switch (parser->current_token->type) {
    case TOKEN_IDENTIFIER:
      return parse_identifier(parser);
    case TOKEN_VARIABLE_TYPE:
      return parse_variable_definition(parser);
    case TOKEN_KEYWORD:
        return parse_keyword(parser);
    default:
      error("parser.parse_statement", "Cannot parse token yet.");
  }

  return NULL;
}

AST_NODE* parse_statements(PARSER* parser){
  AST_NODE* compound = init_ast_node(AST_COMPOUND);
  compound->compound = calloc(1, sizeof(AST_NODE*));
  AST_NODE* statement = parse_statement(parser);
  compound->compound[0] = statement;
  compound->compound_size++;

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
  //TODO: Complete method to parse expression.
  switch (parser->current_token->type) {
    case TOKEN_STRING_LITERAL:
      return parse_string(parser);
    case TOKEN_IDENTIFIER:
      return parse_identifier(parser);
    default:
      error("parser.parse_expression", "Cannot parse token yet.");
  }

  return NULL;
}

AST_NODE* parse_factor(PARSER* parser){
  //TODO: Write a method to parse factors.
  return NULL;
}

AST_NODE* parse_term(PARSER* parser){
  //TODO: Write a method to parse terms.
  return NULL;
}

AST_NODE* parse_function_call(PARSER* parser){
  AST_NODE* function_call = init_ast_node(AST_FUNCTION_CALL);
  function_call->function_call_name = parser->prev_token->value;
  function_call->function_call_args = calloc(1, sizeof(AST_NODE*));
  function_call->args_size++;

  consume_token(parser, TOKEN_LEFT_PARENTHESIS);

  AST_NODE* expr = parse_expression(parser);
  function_call->function_call_args[0] = expr;

  while (parser->current_token->type == TOKEN_COMMA) {
    consume_token(parser, TOKEN_COMMA);
    expr = parse_expression(parser);
    function_call->args_size++;
    function_call->function_call_args = realloc(function_call->function_call_args, function_call->args_size * sizeof(AST_NODE*));
    function_call->function_call_args[function_call->args_size - 1] = expr;
  }
  return function_call;
}

AST_NODE* parse_variable_definition(PARSER* parser) {
  char* variable_type = parser->current_token->value;
  consume_token(parser, TOKEN_VARIABLE_TYPE);
  char* variable_name = parser->current_token->value;
  consume_token(parser, TOKEN_IDENTIFIER);
  consume_token(parser, TOKEN_ASSIGN);
  AST_NODE* variable_value = parse_expression(parser);
  AST_NODE* variable_definition = init_ast_node(AST_VARIABLE_DEFINITION);
  variable_definition->variable_defined_name = variable_name;
  variable_definition->variable_definition = variable_value;
  variable_definition->variable_type = variable_type;
  return variable_definition;
}

AST_NODE* parse_string(PARSER* parser){
  AST_NODE* string = init_ast_node(AST_STRING);
  string->string = parser->current_token->value;
  consume_token(parser, TOKEN_STRING_LITERAL);
  return string;
}

AST_NODE* parse_keyword(PARSER* parser) {
  //TODO: Write method to parse keywords.
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
