#include "s21_test_main.h"

START_TEST(allocate_mem_for_matrix_figure) {
    int **test_matrix = s21_create_matrix(FIGURE_SIZE, FIGURE_SIZE);

    ck_assert_ptr_nonnull(test_matrix);
    for (int i = 0; i < FIGURE_SIZE; i++) {
        ck_assert_ptr_nonnull(test_matrix[i]);
    }

    s21_free_matrix(FIGURE_SIZE, test_matrix);
}
END_TEST

START_TEST(allocate_mem_for_matrix_field) {
    int **test_matrix = s21_create_matrix(WIN_Y, WIN_X);

    ck_assert_ptr_nonnull(test_matrix);
    for (int i = 0; i < FIGURE_SIZE; i++) {
        ck_assert_ptr_nonnull(test_matrix[i]);
    }

    s21_free_matrix(WIN_Y, test_matrix);
}
END_TEST

START_TEST(resest_vals) {
    int **test_matrix = s21_create_matrix(FIGURE_SIZE, FIGURE_SIZE);

    int matrix_to_fill[FIGURE_SIZE][FIGURE_SIZE] = {
        {1, 2, 3, 4}, {4, 3, 2, 1}, {1, 2, 4, 3}, {2, 1, 3, 4}};
    s21_fill_matrix(matrix_to_fill, test_matrix);

    int **test_matrix_zero = s21_create_matrix(FIGURE_SIZE, FIGURE_SIZE);

    s21_reset_matrix(test_matrix, FIGURE_SIZE, FIGURE_SIZE);

    int code = s21_cmp_matrix(test_matrix, test_matrix_zero);

    ck_assert_int_eq(SUCCESS, code);

    s21_free_two_matrices(test_matrix, test_matrix_zero);
}
END_TEST

START_TEST(copy_matrix) {
    int **test_matrix_dst = s21_create_matrix(FIGURE_SIZE, FIGURE_SIZE);

    int matrix_to_fill[FIGURE_SIZE][FIGURE_SIZE] = {
        {1, 2, 3, 4}, {4, 3, 2, 1}, {1, 2, 4, 3}, {2, 1, 3, 4}};
    int **test_matrix_src = s21_create_and_fill(matrix_to_fill);

    s21_copy_matrix(test_matrix_src, test_matrix_dst);

    int code = s21_cmp_matrix(test_matrix_dst, test_matrix_src);

    ck_assert_int_eq(SUCCESS, code);

    s21_free_two_matrices(test_matrix_dst, test_matrix_src);
}
END_TEST

TCase *test_matrix_actions() {
    TCase *tcase = tcase_create("matrix_actions");
    tcase_add_test(tcase, allocate_mem_for_matrix_figure);
    tcase_add_test(tcase, allocate_mem_for_matrix_field);
    tcase_add_test(tcase, resest_vals);
    tcase_add_test(tcase, copy_matrix);

    return tcase;
}