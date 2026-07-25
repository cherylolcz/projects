#include "s21_backend.h"

int **s21_create_matrix(int row, int col) {
    int **matrix = (int **)calloc(row, sizeof(int *));
    if (matrix == NULL) return NULL;

    for (int i = 0; i < row; i++) {
        matrix[i] = (int *)calloc(col, sizeof(int));
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void s21_reset_matrix(int **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = 0;
        }
    }
}

void s21_copy_matrix(int **src, int **dst) {
    for (int i = 0; i < FIGURE_SIZE; i++) {
        for (int j = 0; j < FIGURE_SIZE; j++) {
            dst[i][j] = src[i][j];
        }
    }
}

int s21_free_matrix(int row, int **matrix) {
    if (matrix == NULL) return FAIL;

    for (int i = 0; i < row; i++) {
        if (matrix[i] != NULL) free(matrix[i]);
    }
    free(matrix);

    return SUCCESS;
}

void s21_free_all_matrix(GameData_t *gd) {
    for (int i = 0; i < FIGURE_COUNT; i++)
        s21_free_matrix(FIGURE_SIZE, gd->figure[i]);
    s21_free_matrix(FIGURE_SIZE, gd->g_i.next);
    s21_free_matrix(WIN_Y, gd->g_i.field);
    s21_free_matrix(FIGURE_SIZE, gd->fig_cur.shape);
}