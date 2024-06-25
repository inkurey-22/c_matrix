/*
** EPITECH PROJECT, 2024
** c_matrix
** File description:
** add.c
*/

#include "matrix.h"

matrix_t *add_matrix(matrix_t *m1, matrix_t *m2)
{
    matrix_t *result = create_matrix(m1->rows, m1->cols, NULL);

    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            result->matrix[i][j] = m1->matrix[i][j] + m2->matrix[i][j];
        }
    }
    return result;
}
