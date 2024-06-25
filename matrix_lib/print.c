/*
** EPITECH PROJECT, 2024
** c_matrix
** File description:
** print.c
*/

#include "matrix.h"

void print_matrix(matrix_t *matrix)
{
    int max_length = 0;
    char buffer[50];

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            sprintf(buffer, "%f", matrix->matrix[i][j]);
            int length = strlen(buffer);
            if (length > max_length) {
                max_length = length;
            }
        }
    }
    for (int i = 0; i < matrix->rows; i++) {
        printf("{ ");
        for (int j = 0; j < matrix->cols; j++) {
            printf("%*f", max_length, matrix->matrix[i][j]);
            if (j != matrix->cols - 1) {
                printf(", ");
            }
        }
        printf(" }\n");
    }
}
