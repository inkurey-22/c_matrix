/*
** EPITECH PROJECT, 2024
** c_matrix
** File description:
** power.c
*/

#include "matrix.h"

/*
** Creates a new matrix with the values of the given matrix
** Then multiplies it by the given matrix 'power' times
*/
matrix_t *power_matrix(matrix_t *matrix, int power)
{
    matrix_t *result = create_matrix(matrix->rows, matrix->cols, NULL);
    matrix_t *tmp = create_matrix(matrix->rows, matrix->cols, NULL);

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result->matrix[i][j] = matrix->matrix[i][j];
        }
    }
    for (int i = 0; i < power - 1; i++) {
        tmp = multiply_matrix(result, matrix);
        result = tmp;
    }
    return result;
}
