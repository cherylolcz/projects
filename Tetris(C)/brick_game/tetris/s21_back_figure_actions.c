#include "s21_backend.h"

void s21_fill_figures(int **figure, int index) {
    const int patterns[7][8] = {
        {1, 0, 1, 1, 1, 2, 1, 3},  // I
        {1, 0, 1, 1, 2, 1, 2, 2},  // S
        {1, 1, 1, 2, 2, 0, 2, 1},  // Z
        {1, 1, 2, 1, 2, 2, 2, 3},  // L
        {1, 2, 2, 2, 2, 1, 2, 0},  // J
        {1, 1, 2, 0, 2, 1, 2, 2},  // T
        {1, 1, 1, 2, 2, 1, 2, 2}   // O
    };

    for (int i = 0; i < FIGURE_SIZE; i++) {
        int y = patterns[index][i * 2];
        int x = patterns[index][i * 2 + 1];
        figure[y][x] = 1;
    }
}

void s21_change_figure_pos(GameData_t *gd) {
    switch (gd->g_a) {
        case Left:
        case Right:
        case Down:
        case Drop:
            s21_move_figure(&gd->fig_cur, gd->g_a, gd->g_i.field);
            break;
        case Action:
            s21_rotate_figure(&gd->fig_cur, gd->g_i.field);
            break;
        default:
            break;
    }
}

int s21_can_move(f_cords *cord, int **shape, int **field) {
    for (int i = 0; i < FIGURE_SIZE; i++) {
        for (int j = 0; j < FIGURE_SIZE; j++) {
            if (shape[i][j]) {
                int w_y = cord->y + i;
                int w_x = cord->x + j;

                if (w_x < 1 || w_x >= WIN_X - 1 || w_y >= WIN_Y - 1) {
                    return FAIL;
                }

                if (w_y >= 0 && field[w_y][w_x]) return FAIL;
            }
        }
    }

    return SUCCESS;
}

void s21_move_figure(Figure_t *fig, UserAction_t action, int **field) {
    f_cords new_cords = fig->cord;
    switch (action) {
        case Left:
            new_cords.x--;
            break;
        case Right:
            new_cords.x++;
            break;
        case Down:
            new_cords.y++;
            break;
        case Drop:
            new_cords.y++;
            while (s21_can_move(&new_cords, fig->shape, field) == SUCCESS) {
                fig->cord = new_cords;
                new_cords.y++;
            }
        default:
            break;
    }

    if (s21_can_move(&new_cords, fig->shape, field) == SUCCESS)
        fig->cord = new_cords;
}

void s21_rotate_figure(Figure_t *fig, int **field) {
    int **temp = s21_create_matrix(FIGURE_SIZE, FIGURE_SIZE);

    for (int i = 0; i < FIGURE_SIZE; i++) {
        for (int j = 0; j < FIGURE_SIZE; j++) {
            temp[j][FIGURE_SIZE - i - 1] = fig->shape[i][j];
        }
    }

    if (s21_can_move(&fig->cord, temp, field) == SUCCESS) {
        for (int i = 0; i < FIGURE_SIZE; i++) {
            for (int j = 0; j < FIGURE_SIZE; j++) {
                fig->shape[i][j] = temp[i][j];
            }
        }
    }

    s21_free_matrix(FIGURE_SIZE, temp);
}
