/*
** EPITECH PROJECT, 2024
** c_matrix
** File description:
** set_indiv_value.c
*/

#include "matrix.h"

void set_indiv_value(matrix_t *matrix, int row, int col, double value)
{
    matrix->matrix[row][col] = value;
}
