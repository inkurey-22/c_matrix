/*
** EPITECH PROJECT, 2024
** c_matrix
** File description:
** create.c
*/

#include "matrix.h"

/*
** Initialize a matrix with the given number of rows and columns
** Fills it with the given values or with 0 if values is NULL
*/
matrix_t *create_matrix(int rows, int cols, double *values)
{
    matrix_t *matrix = malloc(sizeof(matrix_t));

    matrix->rows = rows;
    matrix->cols = cols;
    matrix->matrix = malloc(sizeof(double *) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->matrix[i] = malloc(sizeof(double) * cols);
        for (int j = 0; j < cols; j++) {
            if (values == NULL) {
                matrix->matrix[i][j] = 0;
            } else if (values[i * cols + j] != 0){
                matrix->matrix[i][j] = values[i * cols + j];
            } else {
                matrix->matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}
