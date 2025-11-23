#include "matrix.h"

float ** create_matrix_zeros(int n) {
    float ** matrix = (float **)malloc(n * sizeof(float *)) ;
    for (int i = 0; i < n; i++) {
        matrix[i] = (float *)calloc(n, sizeof(float)) ;
    }
    return matrix;
}

float ** copy_matrix(float ** matrix, int n) {
    float ** copy = (float **)malloc(n * sizeof(float *)) ;
    for (int i = 0; i < n; i++) {
        copy[i] = (float *)malloc(n * sizeof(float)) ;
        for (int j = 0; j < n; j++) {
            copy[i][j] = matrix[i][j] ;
        }
    }
    return copy ;
}

float ** multiply_matrix(float ** mat1, float ** mat2, int n) {
    float ** result = create_matrix_zeros(n) ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            float sum = 0 ;
            for (int k = 0; k < n; k++) {
                sum += mat1[i][k] * mat2[k][j] ;
            }
            result[i][j] = sum ;
        }
    }
    return result ;
}

float abs_float(float x) {
    if (x < 0) {
        return -x ;
    }
    return x ;
}

float difference_matrix(float ** mat1, float ** mat2, int n) {
    float result = 0 ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            float diff = mat1[i][j] - mat2[i][j] ;
            result += abs_float(diff) ;
        }
    }
    return result ;
}

void free_matrix(float ** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]) ;
    }
    free(matrix) ;
}

float ** convert_matrix(t_adjacency_list list) {
    int n = list.size ;
    float ** matrix = create_matrix_zeros(n) ;
    for (int i = 0; i < n; i++) {
        t_list current_list = list.vertices[i] ;
        t_cell *current_cell = current_list.head ;
        while (current_cell != NULL) {
            int j = current_cell->vertex ;
            float prob = current_cell->probability ;
            matrix[i][j] = prob ;
            current_cell = current_cell->next ;
        }
    }
    return matrix ;
}

void display_matrix(float **matrix, int n) { // Made with the help of Gemini to have a cleaner display
    for (int i = 0; i < n; i++) {
        printf("|");
        for (int j = 0; j < n; j++) {
            printf(" %1.2f ", matrix[i][j]) ;
        }
        printf("|\n") ;
    }
}