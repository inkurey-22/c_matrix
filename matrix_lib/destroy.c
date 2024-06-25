/*
** EPITECH PROJECT, 2024
** c_matrix
** File description:
** destroy.c
*/

#include "matrix.h"

void destroy_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
        free(matrix->matrix[i]);
    free(matrix->matrix);
    free(matrix);
}
