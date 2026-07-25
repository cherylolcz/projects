#include "s21_backend.h"

GameData_t *s21_init_game_data() {
    static GameData_t gd = {0};
    static bool has_init = false;

    if (!has_init) {
        has_init = true;

        s21_fill_figure_loop(gd.figure);
        gd.g_i = s21_init_game_info();

        gd.fig_cur = s21_init_cur_fig();
        gd.fig_next = s21_init_next_fig(&(gd.g_i.next));

        s21_copy_matrix(gd.figure[gd.fig_cur.type], gd.fig_cur.shape);
        s21_copy_matrix(gd.figure[gd.fig_next.type], gd.g_i.next);

        gd.g_a = Nothing;
        gd.g_s = STATE_MENU;
    }

    return &gd;
}

void s21_fill_figure_loop(int **figure[FIGURE_COUNT]) {
    for (int i = 0; i < FIGURE_COUNT; i++) {
        figure[i] = s21_create_matrix(FIGURE_SIZE, FIGURE_SIZE);
        s21_fill_figures(figure[i], i);
    }
}

GameInfo_t s21_init_game_info() {
    GameInfo_t g_info;

    g_info.field = s21_create_matrix(WIN_Y, WIN_X);
    g_info.next = s21_create_matrix(FIGURE_SIZE, FIGURE_SIZE);
    g_info.score = 0;
    g_info.level = 1;
    g_info.speed = MIN_FALL_DELAY_MS;
    s21_set_record(&g_info);

    return g_info;
}

Figure_t s21_init_cur_fig() {
    Figure_t figure;

    figure.shape = s21_create_matrix(FIGURE_SIZE, FIGURE_SIZE);

    figure.type = rand() % FIGURE_COUNT;

    figure.cord.y = 0;
    figure.cord.x = (WIN_X - FIGURE_SIZE) / 2;

    return figure;
}

Figure_t s21_init_next_fig(int ***shape) {
    Figure_t figure;

    figure.shape = *shape;

    figure.type = rand() % FIGURE_COUNT;

    figure.cord.y = 0;
    figure.cord.x = (INSTR_X - FIGURE_SIZE) / 2;

    return figure;
}