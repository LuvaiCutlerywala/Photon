#ifndef AST_H
#define AST_H

#include <stdlib.h>

/*
 * Types for the different AST nodes. Currently, the types are only inclusive of variable references, variable
 * definitions, function calls, strings, compound statements, and halt. As there are more keywords and other features, some of
 * the types of AST nodes will be added will include control flow statements, etc.
 */
typedef enum ast_type {
  AST_VARIABLE_DEFINITION,
  AST_VARIABLE,
  AST_FUNCTION_CALL,
  AST_STRING,
  AST_COMPOUND,
  AST_HALT
} AST_TYPE;

/*
 * A struct that represents the AST node. The different values are currently all part of the same node, for simplicity,
 * however it would be better practice to have different node types for different nodes. As C does not have a concept of
 * inheritance, due to it being a purely imperative language, this one monolithic AST node is used, along with the enum
 * above, to identify different types of AST nodes.
 */
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

/// @brief Initialises the AST node.
/// @param type The type of AST node to be initialised.
AST_NODE* init_ast_node(AST_TYPE type);

#endif
