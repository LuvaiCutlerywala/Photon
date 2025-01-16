#ifndef INTERNAL_FUNCS_H
#define INTERNAL_FUNCS_H

#include "../src/include/AST.h"
#include "../src/include/visitor.h"

#include <stdlib.h>

AST_NODE* internal_func_print(VISITOR* visitor, AST_NODE** function_call_args, size_t args_size);

#endif
