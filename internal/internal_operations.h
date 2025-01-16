#ifndef INTERNAL_OPERATIONS_H
#define INTERNAL_OPERATIONS_H

//TODO: Create functions for basic operations in the photon language.

long internal_op_add(long a, long b);
long internal_op_subtract(long a, long b);
long internal_op_multiply(long a, long b);
long internal_op_divide(long a, long b);

void chk_precision(long a, long b);

#endif
