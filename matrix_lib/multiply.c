/*
** EPITECH PROJECT, 2024
** c_matrix
** File description:
** multiply.c
*/

#include "matrix.h"

/*
** Allocates a new matrix and fills it with the product of the two given matrices
*/
matrix_t *multiply_matrix(matrix_t *m1, matrix_t *m2)
{
    matrix_t *result = create_matrix(m1->rows, m2->cols, NULL);

    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            for (int k = 0; k < m1->cols; k++) {
                result->matrix[i][j] += m1->matrix[i][k] * m2->matrix[k][j];
            }
        }
    }
    return result;
}
