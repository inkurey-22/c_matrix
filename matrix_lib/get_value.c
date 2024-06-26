/*
** EPITECH PROJECT, 2024
** c_matrix
** File description:
** get_value.c
*/

#include "matrix.h"

double get_value(matrix_t *matrix, int row, int col)
{
    return matrix->matrix[row][col];
}
