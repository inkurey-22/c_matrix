/*
** EPITECH PROJECT, 2024
** c_matrix
** File description:
** transpose.c
*/

#include "matrix.h"

/*
** Goes through the given matrix and put the values in the new matrix in the opposite order
*/
matrix_t *transpose_matrix(matrix_t *matrix)
{
    matrix_t *result = create_matrix(matrix->rows, matrix->cols, NULL);

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result->matrix[j][i] = matrix->matrix[i][j];
        }
    }
    return result;
}
