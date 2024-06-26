/*
** EPITECH PROJECT, 2024
** c_matrix
** File description:
** determinant.c
*/

#include "matrix.h"

static matrix_t *create_sub_matrix(matrix_t *matrix, int ex_row, int ex_col)
{
    matrix_t *sub_matrix = create_matrix(matrix->rows - 1, matrix->cols - 1, NULL);
    int sub_i = 0;

    for (int i = 0; i < matrix->rows; i++) {
        if (i == ex_row)
            continue;
        int sub_j = 0;

        for (int j = 0; j < matrix->cols; j++) {
            if (j == ex_col) continue;
            sub_matrix->matrix[sub_i][sub_j] = matrix->matrix[i][j];
            sub_j++;
        }
        sub_i++;
    }
    return sub_matrix;
}

double determinant(matrix_t *matrix)
{
    double det = 0;
    int sign = 1;

    if (matrix->rows != matrix->cols) {
        printf("Error: matrix is not square\n");
        return -1;
    }
    if (matrix->rows == 1) {
        return get_value(matrix, 0, 0);
    } else if (matrix->rows == 2) {
        return get_value(matrix, 0, 0) * get_value(matrix, 1, 1) - get_value(matrix, 0, 1) * get_value(matrix, 1, 0);
    } else {
        for (int i = 0; i < matrix->cols; i++) {
            matrix_t *sub_matrix = create_sub_matrix(matrix, 0, i);
            det += sign * get_value(matrix, 0, i) * determinant(sub_matrix);
            destroy_matrix(sub_matrix);
            sign = -sign;
        }
    }
    return det;
}
