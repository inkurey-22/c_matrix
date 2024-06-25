/*
** EPITECH PROJECT, 2024
** c_matrix
** File description:
** scalar.c
*/

#include "matrix.h"


/*
** Allocates a new matrix and multiply each value of the given matrix by the given scalar
*/
matrix_t *scalar_matrix(matrix_t *matrix, double scalar)
{
    matrix_t *result = create_matrix(matrix->rows, matrix->cols, NULL);

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result->matrix[i][j] = matrix->matrix[i][j] * scalar;
        }
    }
    return result;
}
