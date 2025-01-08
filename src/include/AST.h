#ifndef AST_H
#define AST_H

#include <stdlib.h>

typedef enum ast_type {
  AST_VARIABLE_DEFINITION,
  AST_VARIABLE,
  AST_FUNCTION_CALL,
  AST_STRING,
  AST_COMPOUND
} AST_TYPE;

typedef struct AST_NODE {
  AST_TYPE type;

  //AST_VARIABLE_DEFINITION
  char* variable_defined_name;
  char* variable_type;
  struct AST_NODE* variable_definition;

  //AST_VARIABLE
  char* variable_name;

  //AST_FUNCTION_CALL
  char* function_call_name;
  struct AST_NODE** function_call_args;
  size_t args_size;

  //AST_STRING
  char* string;

  //AST_COMPOUND
  struct AST_NODE** compound;
  size_t compound_size;
} AST_NODE;

AST_NODE* init_ast_node(AST_TYPE type);

#endif
