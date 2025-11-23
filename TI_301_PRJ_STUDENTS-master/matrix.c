#include "matrix.h"

/**
* @brief Creates an n x n matrix filled with the value 0.
*
* @param n The dimension (number of rows and columns) of the matrix.
* @return float** The n x n matrix initialized with zeros.
*/
float ** create_matrix_zeros(int n) {
    float ** matrix = (float **)malloc(n * sizeof(float *)) ;
    for (int i = 0; i < n; i++) {
        matrix[i] = (float *)calloc(n, sizeof(float)) ;
    }
    return matrix;
}

/**
* @brief Creates a copy of a given matrix of size n.
*
* @param matrix The source matrix to be copied.
* @param n The dimension (number of rows and columns) of the matrix.
* @return float** A new matrix containing the same values as the source matrix.
*/
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

/**
 * @brief Multiplies two n x n matrices.
 *
 * @param mat1 The first matrix.
 * @param mat2 The second matrix.
 * @param n The dimension (number of rows and columns) of the matrices.
 * @return float** The resulting matrix product.
 */
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


/**
 * @brief Calculates the absolute value of a floating-point number.
 *
 * @param x The input number.
 * @return float The absolute value of x.
 */
float abs_float(float x) {
    if (x < 0) {
        return -x ;
    }
    return x ;
}

/**
 * @brief Calculates the total difference between two matrices.
 *
 * This function computes the sum of the absolute differences between
 * corresponding coefficients of the two matrices[cite: 406].
 *
 * @param mat1 The first matrix.
 * @param mat2 The second matrix.
 * @param n The dimension of the matrices.
 * @return float The sum of absolute differences.
 */
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

/**
 * @brief Frees the memory allocated for an n x n matrix.
 *
 * @param matrix The matrix to free.
 * @param n The dimension of the matrix.
 */
void free_matrix(float ** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]) ;
    }
    free(matrix) ;
}

/**
 * @brief Converts an adjacency list (graph) into a transition matrix.
 *
 * Each element M[i][j] represents the probability of moving from
 * vertex i to vertex j[cite: 401].
 *
 * @param list The adjacency list representation of the graph.
 * @return float** The corresponding n x n transition matrix.
 */
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

/**
 * @brief Displays an n x n matrix to the standard output.
 *
 * @param matrix The matrix to display.
 * @param n The dimension of the matrix.
 */
void display_matrix(float **matrix, int n) { // Made with the help of Gemini to have a cleaner display
    for (int i = 0; i < n; i++) {
        printf("|");
        for (int j = 0; j < n; j++) {
            printf(" %1.2f ", matrix[i][j]) ;
        }
        printf("|\n") ;
    }
}

/**
 * @brief Creates an n x n identity matrix.
 *
 * @param n The dimension of the matrix.
 * @return float** The identity matrix (1s on diagonal, 0s elsewhere).
 */
float ** identity_matrix(int n) {
    float **matrix = create_matrix_zeros(n) ;
    for (int i = 0; i < n; i++) {
        matrix[i][i] = 1 ;
    }
    return matrix ;
}

/**
 * @brief Calculates the power of a matrix (M^k).
 *
 * This function iteratively multiplies the matrix by itself k times
 * to simulate the evolution of probabilities after k steps[cite: 331].
 *
 * @param matrix The base matrix.
 * @param n The dimension of the matrix.
 * @param k The exponent (number of steps).
 * @return float** The resulting matrix raised to the power k.
 */
float ** power_matrix(float ** matrix, int n, int k) {
    if (k < 0) {
        printf("Error: k must be positive\n") ;
        return NULL ;
    }
    if (k == 0) {
        return identity_matrix(n) ;
    }
    if (k == 1) {
        return copy_matrix(matrix, n) ;
    }
    float ** result = copy_matrix(matrix, n) ;
    float ** temp = NULL ;
    for (int i = 2; i <= k; i++) {
        temp = multiply_matrix(result, matrix, n) ;
        free_matrix(result, n) ; // I asked Gemini if there were any problems and it suggested this fix to avoid a memory leak
        result = temp ;
    }
    return result ;
}


/**
* @brief Extracts a submatrix corresponding to a specific
component of a graph partition.
*
* @param matrix The original adjacency matrix of the graph.
* @param part The partition of the graph into strongly
connected components.
* @param compo_index The index of the component to extract.
* @return t_matrix The submatrix corresponding to the
specified component.
*/
float ** subMatrix(float ** matrix, t_partition part, int compo_index, int * n_sub) { // Made with a bit of help from Gemini to understand what the function is supposed to do
    t_class_cell * current_class = part.head ;
    t_class * class = NULL ;
    int current_index = 0, found = 0 ;
    while (current_class != NULL && !found) {
        if (current_index == compo_index) {
            class = current_class->class ;
            found = 1 ;
        } else {
            current_class = current_class->next ;
            current_index++ ;
        }
    }
    *n_sub = 0 ;
    t_tarjan_cell * current_vertex = class->head ;
    while (current_vertex != NULL) {
        (*n_sub)++ ;
        current_vertex = current_vertex->next ;
    }
    int * vertices = (int *)malloc((*n_sub) * sizeof(int)) ;
    current_vertex = class->head ;
    for (int i = 0; i < *n_sub; i++) {
        vertices[i] = current_vertex->vertex->identifier-1 ;
        current_vertex = current_vertex->next ;
    }
    float ** sub_matrix = create_matrix_zeros(*n_sub);
    for (int i = 0; i < *n_sub; i++) { // Line of the sub-matrix
        int i_matrix = vertices[i] ; // Line of the original matrix
        for (int j = 0; j < *n_sub; j++) { // Column of the sub-matrix
            int j_matrix = vertices[j] ; // Column of the original matrix
            sub_matrix[i][j] = matrix[i_matrix][j_matrix] ;
        }
    }
    free(vertices) ;
    return sub_matrix ;
}


/**
 * @brief Tests the convergence of the transition matrix to find a stationary distribution.
 *
 * It iteratively computes powers of the matrix (M^n) until the difference between
 * M^n and M^(n-1) is less than a defined threshold (epsilon = 0.01).
 * If convergence is reached, it displays the resulting stationary matrix.
 *
 * @param M The initial transition matrix.
 * @param n The dimension (number of rows/columns) of the matrix.
 * @return int Status code (implicitly 1 if converged, though the return statement is missing in this snippet).
 */
int test_convergence(float ** M, int n) {
    float epsilon = 0.01 ;
    float ** Mprev = copy_matrix(M, n) ;
    float diff = 1.0 ;
    int cpt = 2 ;
    const int max_iter = 100 ;
    printf("\n--- Original transition matrix ---\n") ;
    display_matrix(Mprev, n) ;
    while (diff > epsilon && cpt <= max_iter) {
        float ** M_n = multiply_matrix(Mprev, M, n) ;
        diff = difference_matrix(M_n, Mprev, n) ;
        if (diff <= epsilon) {
            printf("\n--- Convergence Reached ---\n") ;
            printf("Matrix found between powers n = %d and n = %d.\n", cpt-1, cpt) ;
            printf("Resulting Matrix :\n", cpt) ;
            display_matrix(M_n, n);
        }
        free_matrix(Mprev, n) ;
        Mprev = M_n ;
        cpt++ ;
    }
    if (cpt > max_iter && diff > epsilon) {
        printf("\n--- No convergence found ---\n") ;
        printf("Convergence was not reached before %d iterations.\n", max_iter) ;
    }
    free_matrix(Mprev, n) ;
    free_matrix(M, n) ;
}