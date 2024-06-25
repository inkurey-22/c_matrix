/*
** EPITECH PROJECT, 2024
** c_matrix
** File description:
** rank.c
*/

#include "matrix.h"

static matrix_t *copy_matrix(matrix_t *matrix)
{
    matrix_t *copy = create_matrix(matrix->rows, matrix->cols, NULL);

    for (int i = 0; i < matrix->rows; i++)
        for (int j = 0; j < matrix->cols; j++)
            copy->matrix[i][j] = matrix->matrix[i][j];
    return copy;
}

static void transform_to_row_echelon(matrix_t *matrix)
{
    for (int i = 0; i < matrix->rows; i++) {
        double maxEl = fabs(matrix->matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < matrix->rows; k++) {
            if (fabs(matrix->matrix[k][i]) > maxEl) {
                maxEl = fabs(matrix->matrix[k][i]);
                maxRow = k;
            }
        }

        for (int k = i; k < matrix->cols; k++) {
            double tmp = matrix->matrix[maxRow][k];
            matrix->matrix[maxRow][k] = matrix->matrix[i][k];
            matrix->matrix[i][k] = tmp;
        }

        for (int k = i + 1; k < matrix->rows; k++) {
            double c = -matrix->matrix[k][i] / matrix->matrix[i][i];
            for (int j = i; j < matrix->cols; j++) {
                if (i == j) {
                    matrix->matrix[k][j] = 0;
                } else {
                    matrix->matrix[k][j] += c * matrix->matrix[i][j];
                }
            }
        }
    }
}

static int count_non_zero_rows(matrix_t *matrix)
{
    int count = 0;

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            if (matrix->matrix[i][j] != 0) {
                count++;
                break;
            }
        }
    }

    return count;
}

int rank(matrix_t *matrix)
{
    matrix_t *copy = copy_matrix(matrix);
    transform_to_row_echelon(copy);
    int rank = count_non_zero_rows(copy);
    destroy_matrix(copy);
    return rank;
}
