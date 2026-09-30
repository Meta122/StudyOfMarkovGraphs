#ifndef MATRIX_H
#define MATRIX_H
#include "Tarjan Algorithm/tarjan_algo.h"

float ** create_matrix_zeros(int) ;
float ** copy_matrix(float **, int) ;
float ** multiply_matrix(float **, float **, int) ;
float abs_float(float) ;
float difference_matrix(float **, float **, int) ;
void free_matrix(float **, int) ;
float ** convert_matrix(t_adjacency_list) ;
void display_matrix(float **, int) ;
float ** identity_matrix(int) ;
float ** power_matrix(float **, int, int);
float ** subMatrix(float **, t_partition, int, int *) ;
int test_convergence(float **, int) ;

#endif //MATRIX_H