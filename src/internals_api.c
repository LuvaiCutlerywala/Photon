#include "internals_api.h"

#include <logging/logger.h>

AST_NODE* internal_api_func_print(VISITOR* visitor, AST_NODE** function_call_args, size_t args_size){
    for(unsigned long i = 0; i < args_size; i++) {
        AST_NODE* visited_node = visit(visitor, function_call_args[i]);

        switch(visited_node->type){
            case AST_STRING:
                internal_func_print(visited_node->string);
                break;
            default:
                error("visitor.internal_func_print", "Unexpected node type");
                exit(1);
        }
    }

    return init_ast_node(AST_HALT);
}

AST_NODE* internal_api_op_add(VISITOR* visitor, AST_NODE** arithmetic_args) {
    long a, b;
    AST_NODE* operand = visit(visitor, arithmetic_args[0]);
    if (operand->type == AST_INTEGER) {

    } else if (operand->type == AST_REAL) {

    } else {

    }
}

AST_NODE* internal_api_op_subtract(VISITOR* visitor, AST_NODE** arithmetic_args) {

}

AST_NODE* internal_api_op_multiply(VISITOR* visitor, AST_NODE** arithmetic_args) {

}

AST_NODE* internal_api_op_divide(VISITOR* visitor, AST_NODE** arithmetic_args) {

}
