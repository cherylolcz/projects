#ifndef S21_TEST_H
#define S21_TEST_H

#include <check.h>

#include "../brick_game/tetris/controller/s21_tetris_controller.h"
#include "../brick_game/tetris/s21_backend.h"
#include "../gui/cli/s21_frontend.h"

#define FIGURE_TYPE 3

void s21_fill_matrix(int src[FIGURE_SIZE][FIGURE_SIZE], int **dst);
int s21_cmp_matrix(int **a, int **b);
int **s21_create_and_fill(int fill[FIGURE_SIZE][FIGURE_SIZE]);
void s21_free_two_matrices(int **a, int **b);
Figure_t s21_create_test_figure(int y, int x);

#endif  //  S21_TEST_H