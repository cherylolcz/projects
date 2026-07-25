#include "controller/s21_tetris_controller.h"
#include "s21_backend.h"

void s21_reset_vals(GameData_t *gd) {
    gd->fig_cur.type = gd->fig_next.type;
    gd->fig_next.type = rand() % FIGURE_COUNT;

    gd->fig_cur.cord.y = 1;
    gd->fig_cur.cord.x = (WIN_X - FIGURE_SIZE) / 2;

    s21_copy_matrix(gd->fig_next.shape, gd->fig_cur.shape);
    s21_copy_matrix(gd->figure[gd->fig_next.type], gd->g_i.next);
}

void s21_timer(GameData_t *gd, clock_t *last_fall) {
    clock_t now = clock();
    double elapsed = (now - *last_fall) * 1000.0 / CLOCKS_PER_SEC;

    if (elapsed >= gd->g_i.speed) {
        f_cords new_cords = gd->fig_cur.cord;
        new_cords.y++;

        if (s21_can_move(&new_cords, gd->fig_cur.shape, gd->g_i.field) ==
            SUCCESS)
            gd->fig_cur.cord = new_cords;
        else {
            if (gd->fig_cur.cord.y <= 1) {
                gd->g_s = STATE_GAME_OVER;
                s21_set_record(&gd->g_i);
                gd->g_i.score = 0;
                gd->g_i.level = 1;
                gd->g_i.speed = MIN_FALL_DELAY_MS;
            } else {
                gd->g_i = updateCurrentState();
                s21_reset_vals(gd);
            }
        }
        *last_fall = now;
    }
}

int s21_delete_full_line(int **field) {
    int cleared = 0;
    for (int j = WIN_Y - 2; j >= 0; j--) {
        int full = 1;
        for (int i = 1; i < WIN_X - 1; i++) {
            if (!field[j][i]) {
                full = 0;
                break;
            }
        }

        if (full) {
            cleared++;

            for (int k = j; k > 0; k--)
                memcpy(field[k], field[k - 1], WIN_X * sizeof(int));
            memset(field[1], 0, WIN_X * sizeof(int));
            j++;
        }
    }
    return cleared;
}

void s21_save_field(int **field, Figure_t *fig) {
    for (int i = 0; i < FIGURE_SIZE; i++) {
        for (int j = 0; j < FIGURE_SIZE; j++) {
            int w_y = fig->cord.y + i;
            int w_x = fig->cord.x + j;

            if (fig->shape[i][j]) field[w_y][w_x] = fig->shape[i][j];
        }
    }
}