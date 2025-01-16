#ifndef INTERNALS_API_H
#define INTERNALS_API_H

#include <internal/internal_functions.h>
#include <internal/internal_operations.h>

#include "visitor.h"
#include "AST.h"

// Internal Functions.
AST_NODE* internal_api_func_print(VISITOR* visitor, AST_NODE** function_call_args, size_t args_size);

// Internal operations.
AST_NODE* internal_api_op_add(VISITOR* visitor, AST_NODE** arithmetic_args);
AST_NODE* internal_api_op_subtract(VISITOR* visitor, AST_NODE** arithmetic_args);
AST_NODE* internal_api_op_multiply(VISITOR* visitor, AST_NODE** arithmetic_args);
AST_NODE* internal_api_op_divide(VISITOR* visitor, AST_NODE** arithmetic_args);
#endif
