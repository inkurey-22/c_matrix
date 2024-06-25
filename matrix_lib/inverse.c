/*
** EPITECH PROJECT, 2024
** c_matrix
** File description:
** inverse.c
*/

#include "matrix.h"

/*
** Creates an augmented matrix [A|I] from the given matrix.
** The augmented matrix is used in the process of finding the inverse of a matrix.
*/
static void create_augmented_matrix(matrix_t *matrix, matrix_t *augmented)
{
    int size = matrix->rows;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            augmented->matrix[i][j] = matrix->matrix[i][j];
            augmented->matrix[i][j + size] = (i == j) ? 1 : 0;
        }
    }
}

/*
** Swaps two rows in the given matrix.
** This function is used in the Gauss-Jordan elimination method to find the inverse of a matrix.
*/
static void swap_rows(matrix_t *matrix, int row1, int row2, int col_start, int col_end)
{
    for (int k = col_start; k < col_end; k++) {
        double tmp = matrix->matrix[row1][k];
        matrix->matrix[row1][k] = matrix->matrix[row2][k];
        matrix->matrix[row2][k] = tmp;
    }
}

/*
** Normalizes a row in the given matrix so that the diagonal element is 1.
** This function is used in the Gauss-Jordan elimination method to find the inverse of a matrix.
*/
static void normalize_row(matrix_t *matrix, int row, int col_start, int col_end)
{
    double pivot = matrix->matrix[row][row];
    for (int k = col_start; k < col_end; k++) {
        matrix->matrix[row][k] /= pivot;
    }
}

/*
** Makes all other elements in the current column equal to 0, except the diagonal element.
** This function is used in the Gauss-Jordan elimination method to find the inverse of a matrix.
*/
static void eliminate_column(matrix_t *matrix, int col, int row_start, int row_end)
{
    for (int k = row_start; k < row_end; k++) {
        if (k != col) {
            double scale = matrix->matrix[k][col];
            for (int j = col; j < 2*row_end; j++) {
                matrix->matrix[k][j] -= scale * matrix->matrix[col][j];
            }
        }
    }
}

/*
** Extracts the inverse matrix from the right half of the augmented matrix.
** This function is used after the Gauss-Jordan elimination method to find the inverse of a matrix.
*/
static matrix_t *extract_inverse(matrix_t *augmented)
{
    int size = augmented->rows;
    matrix_t *inverse = create_matrix(size, size, NULL);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inverse->matrix[i][j] = augmented->matrix[i][j + size];
        }
    }
    return inverse;
}

/*
** Calculates the inverse of a given matrix using the Gauss-Jordan elimination method.
** If the given matrix is not square, the function returns NULL and prints an error message.
*/
matrix_t *inverse_matrix(matrix_t *matrix)
{
    if (matrix->rows != matrix->cols) {
        fprintf(stderr, "Error: Only square matrices can be inverted\n");
        return NULL;
    }

    int size = matrix->rows;
    matrix_t *augmented = create_matrix(size, 2*size, NULL);

    create_augmented_matrix(matrix, augmented);
    for (int i = 0; i < size; i++) {
        double maxEl = fabs(augmented->matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < size; k++) {
            if (fabs(augmented->matrix[k][i]) > maxEl) {
                maxEl = fabs(augmented->matrix[k][i]);
                maxRow = k;
            }
        }
        swap_rows(augmented, i, maxRow, i, 2*size);
        normalize_row(augmented, i, i, 2*size);
        eliminate_column(augmented, i, 0, size);
    }
    matrix_t *inverse = extract_inverse(augmented);
    destroy_matrix(augmented);
    return inverse;
}
