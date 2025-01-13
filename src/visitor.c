#include "include/visitor.h"

#include <stdlib.h>
#include <logging/logger.h>

AST_NODE* visit(AST_NODE* node){
  switch(node->type){
    case AST_VARIABLE_DEFINITION:
      return visit_variable_definition(node);
    case AST_VARIABLE:
      return visit_variable(node);
    case AST_FUNCTION_CALL:
      return visit_function_call(node);
    case AST_STRING:
      return visit_string(node);
    case AST_COMPOUND:
      return visit_compound(node);
    default:
      error("visitor.visit", "Unrecognized node type.");
      exit(1);
  }
}

AST_NODE* visit_variable_definition(AST_NODE* node){
    return NULL;
}

AST_NODE* visit_variable(AST_NODE* node){
    return NULL;
}

AST_NODE* visit_function_call(AST_NODE* node){
    return NULL;
}

AST_NODE* visit_string(AST_NODE* node){
    return NULL;
}

AST_NODE* visit_compound(AST_NODE* node){
  for(unsigned long i = 0; i < node->compound_size; i++){
    visit(node->compound[i]);
  }
    return init_ast_node(AST_HALT);
}
