#ifndef MATRIX_H
#define MATRIX_H
#include "list.h"

float * create_matrix_zeros(int n);

float * copy_matrix(float * matr);

float * multiply_matrix(float * matr1, float * matr2);

float difference_matrix(float * matr1, float * matr2);

#endif //MATRIX_H