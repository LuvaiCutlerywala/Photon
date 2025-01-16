#include "internal_functions.h"

#include <../logging/logger.h>

AST_NODE* internal_func_print(VISITOR* visitor, AST_NODE** function_call_args, size_t args_size) {
    debug("visitor.internal_func_print", "Calling internal function 'print.'");
    for(unsigned long i = 0; i < args_size; i++) {
        AST_NODE* visited_node = visit(visitor, function_call_args[i]);

        switch(visited_node->type){
            case AST_STRING:
                fprintf(stdout, "%s\n", visited_node->string);
            default:
                error("visitor.internal_func_print", "Unexpected node type");
            exit(1);
        }
    }

    return init_ast_node(AST_HALT);
}
