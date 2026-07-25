#include "s21_test_main.h"

Suite *suite_tetris();
extern TCase *test_matrix_actions();
extern TCase *test_figure_actions();
extern TCase *test_field_actions();
extern TCase *test_change_stat();
extern TCase *test_init();
extern TCase *test_controller();

int main() {
    Suite *container = suite_tetris();
    SRunner *runner = srunner_create(container);
    srunner_set_fork_status(runner, CK_FORK);
    srunner_run_all(runner, CK_VERBOSE);

    int failed_tests = srunner_ntests_failed(runner);
    srunner_free(runner);

    return failed_tests == 0 ? 0 : 1;
}

Suite *suite_tetris() {
    Suite *container = suite_create("tetris");

    suite_add_tcase(container, test_matrix_actions());
    suite_add_tcase(container, test_change_stat());
    suite_add_tcase(container, test_figure_actions());
    suite_add_tcase(container, test_field_actions());
    suite_add_tcase(container, test_init());
    suite_add_tcase(container, test_controller());

    return container;
}

void s21_fill_matrix(int src[FIGURE_SIZE][FIGURE_SIZE], int **dst) {
    for (int i = 0; i < FIGURE_SIZE; i++) {
        for (int j = 0; j < FIGURE_SIZE; j++) {
            dst[i][j] = src[i][j];
        }
    }
}

int s21_cmp_matrix(int **a, int **b) {
    for (int i = 0; i < FIGURE_SIZE; i++) {
        for (int j = 0; j < FIGURE_SIZE; j++) {
            if (a[i][j] != b[i][j]) return FAIL;
        }
    }
    return SUCCESS;
}

int **s21_create_and_fill(int fill[FIGURE_SIZE][FIGURE_SIZE]) {
    int **mat = s21_create_matrix(FIGURE_SIZE, FIGURE_SIZE);
    s21_fill_matrix(fill, mat);
    return mat;
}

void s21_free_two_matrices(int **a, int **b) {
    s21_free_matrix(FIGURE_SIZE, a);
    s21_free_matrix(FIGURE_SIZE, b);
}

Figure_t s21_create_test_figure(int y, int x) {
    Figure_t test_fig;
    test_fig.shape = s21_create_matrix(FIGURE_SIZE, FIGURE_SIZE);
    s21_fill_figures(test_fig.shape, FIGURE_TYPE);
    test_fig.type = FIGURE_TYPE;
    test_fig.cord.y = y;
    test_fig.cord.x = x;

    return test_fig;
}