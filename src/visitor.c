#include "include/visitor.h"
#include "include/internals_api.h"

#include <stdlib.h>
#include <string.h>
#include <logging/logger.h>

VISITOR* init_visitor(void){
  VISITOR* visitor = calloc(1, sizeof(VISITOR));
  visitor->variable_definitions = NULL;
  visitor->variable_definitions_size = 0;

  return visitor;
}

AST_NODE* visit(VISITOR* visitor, AST_NODE* node){
  switch(node->type){
    case AST_VARIABLE_DEFINITION:
      return visit_variable_definition(visitor, node);
    case AST_VARIABLE:
      return visit_variable(visitor, node);
    case AST_FUNCTION_CALL:
      return visit_function_call(visitor, node);
    case AST_STRING:
      return visit_string(visitor, node);
    case AST_COMPOUND:
      return visit_compound(visitor, node);
    default:
      error("visitor.visit", "Unrecognized node type.");
      exit(1);
  }
}

AST_NODE* visit_variable_definition(VISITOR* visitor, AST_NODE* node){
  visitor->variable_definitions_size++;
  visitor->variable_definitions = realloc(visitor->variable_definitions, visitor->variable_definitions_size * sizeof(AST_NODE*));
  visitor->variable_definitions[visitor->variable_definitions_size - 1] = node;
  return node;
}

AST_NODE* visit_variable(VISITOR* visitor, AST_NODE* node){
  for(unsigned long i = 0; i < visitor->variable_definitions_size; i++){
    AST_NODE* var_def = visitor->variable_definitions[i];
    if(strcmp(var_def->variable_defined_name, node->variable_name) == 0){
      return visit(visitor, var_def->variable_definition);
    }
  }
  error("visitor.visit_variable", "Undefined variable.");
  exit(1);
}

AST_NODE* visit_function_call(VISITOR* visitor, AST_NODE* node){
  if(strcmp(node->function_call_name, "print") == 0){
    return internal_api_func_print(visitor, node->function_call_args, node->args_size);
  }

  return init_ast_node(AST_HALT);
}

AST_NODE* visit_string(VISITOR* visitor, AST_NODE* node){
    return node;
}

AST_NODE* visit_compound(VISITOR* visitor, AST_NODE* node){
  for(unsigned long i = 0; i < node->compound_size; i++){
    visit(visitor, node->compound[i]);
  }
    return init_ast_node(AST_HALT);
}
