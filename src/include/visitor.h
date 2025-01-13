#ifndef VISITOR_H
#define VISITOR_H

#include "AST.h"

AST_NODE* visit(AST_NODE* node);
AST_NODE* visit_variable_definition(AST_NODE* node);
AST_NODE* visit_variable(AST_NODE* node);
AST_NODE* visit_function_call(AST_NODE* node);
AST_NODE* visit_string(AST_NODE* node);
AST_NODE* visit_compound(AST_NODE* node);

#endif
