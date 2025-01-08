#include "AST.h"

AST_NODE* init_ast_node(AST_TYPE type) {
  AST_NODE* node = calloc(1, sizeof(AST_NODE));
  node->type = type;
  node->variable_defined_name = NULL;
  node->variable_definition = NULL;
  node->variable_name = NULL;
  node->function_call_name = NULL;
  node->function_call_args = NULL;
  node->function_call_args = NULL;
  node->args_size = 0;
  node->string = NULL;
  node->compound = NULL;
  node->compound_size = 0;

  return node;
}
