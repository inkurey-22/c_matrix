/*
** EPITECH PROJECT, 2024
** c_matrix
** File description:
** matrix.h
*/

#ifndef C_MATRIX_H
    #define C_MATRIX_H

    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>

typedef struct matrix {
    int rows;
    int cols;
    double **matrix;
} matrix_t;

matrix_t *create_matrix(int rows, int cols, double *values);
matrix_t *add_matrix(matrix_t *m1, matrix_t *m2);
matrix_t *sub_matrix(matrix_t *m1, matrix_t *m2);
matrix_t *multiply_matrix(matrix_t *m1, matrix_t *m2);
matrix_t *power_matrix(matrix_t *matrix, int power);
matrix_t *scalar_matrix(matrix_t *matrix, double scalar);
matrix_t *transpose_matrix(matrix_t *matrix);
matrix_t *inverse_matrix(matrix_t *matrix);

int rank(matrix_t *matrix);

double get_value(matrix_t *matrix, int row, int col);
double determinant_matrix(matrix_t *matrix);
double trace(matrix_t *matrix);

void destroy_matrix(matrix_t *matrix);
void print_matrix(matrix_t *matrix);
void set_indiv_value(matrix_t *matrix, int row, int col, double value);
void set_matrix(matrix_t *matrix, double **new_matrix);

#endif
