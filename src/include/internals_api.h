#ifndef INTERNALS_API_H
#define INTERNALS_API_H

#include <internal/internal_functions.h>
#include <internal/internal_operations.h>

#include "visitor.h"
#include "AST.h"

AST_NODE* internal_api_func_print(VISITOR* visitor, AST_NODE** function_call_args, size_t args_size);

#endif
