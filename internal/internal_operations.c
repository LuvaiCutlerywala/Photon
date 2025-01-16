#include "internal_operations.h"

#include <limits.h>
#include <stdlib.h>
#include <logging/logger.h>

long internal_op_add(long a, long b) {
    chk_precision(a, b);
    return a + b;
}

long internal_op_subtract(long a, long b) {
    chk_precision(a, b);
    return a - b;
}

long internal_op_multiply(long a, long b) {
    chk_precision(a, b);
    return a * b;
}

long internal_op_divide(long a, long b) {
    chk_precision(a, b);
    return a / b;
}

void chk_precision(long a, long b) {
    if (a == LONG_MAX ||
        a == LONG_MIN ||
        b == LONG_MAX ||
        b == LONG_MIN)
    {
        error("internal_operations.chk_precision", "Precision failure, operands are max/min value for type.");
        exit(1);
    }
}