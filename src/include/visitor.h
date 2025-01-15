#ifndef VISITOR_H
#define VISITOR_H

#include "AST.h"

typedef struct visitor {
    AST_NODE** variable_definitions;
    size_t variable_definitions_size;
} VISITOR;

VISITOR* init_visitor(void);

AST_NODE* visit(VISITOR* visitor, AST_NODE* node);
AST_NODE* visit_variable_definition(VISITOR* visitor, AST_NODE* node);
AST_NODE* visit_variable(VISITOR* visitor, AST_NODE* node);
AST_NODE* visit_function_call(VISITOR* visitor, AST_NODE* node);
AST_NODE* visit_string(VISITOR* visitor, AST_NODE* node);
AST_NODE* visit_compound(VISITOR* visitor, AST_NODE* node);

#endif
