#include "s21_frontend.h"

void s21_init_ncurse() {
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    cbreak();
    nodelay(stdscr, TRUE);
}

void s21_init_colors() {
    start_color();
    init_color(8, 400, 700, 1000);

    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    init_pair(8, 8, COLOR_BLACK);
}

void s21_init_windows(Windows_t *windows, WindowsCord win_cords) {
    windows->main_win = newwin(WIN_Y, WIN_X, win_cords.wy, win_cords.wx);
    box(windows->main_win, 0, 0);
    wbkgd(windows->main_win, '.');

    wrefresh(windows->main_win);

    windows->instr = newwin(INSTR_Y, INSTR_X, win_cords.iy, win_cords.ix);
    box(windows->instr, 0, 0);
    s21_fill_window(windows->instr, INSTR);

    windows->game_over =
        derwin(windows->main_win, G_O_Y, G_O_X, win_cords.goy, win_cords.gox);

    windows->pause = derwin(windows->main_win, PAUSE_Y, PAUSE_X, win_cords.goy,
                            win_cords.gox - 1);

    windows->next_figure =
        newwin(NEXT_Y, NEXT_X, win_cords.iy, win_cords.sbx + 2);
    box(windows->next_figure, 0, 0);
    s21_fill_window(windows->next_figure, NEXT);

    windows->stats = newwin(INSTR_Y - NEXT_Y - 1, STAT_X,
                            win_cords.iy + NEXT_Y + 1, win_cords.sbx);
    box(windows->stats, 0, 0);
    s21_fill_window(windows->stats, STAT);
}

void s21_calc_start_cords(WindowsCord *win_cords) {
    win_cords->wy = (LINES - WIN_Y) / 2;
    win_cords->wx = (COLS - WIN_X) / 2;
    win_cords->iy = win_cords->wy + 2;
    win_cords->ix = ((COLS - WIN_X) / 2) - INSTR_X - 2;
    win_cords->goy = (WIN_Y - G_O_Y) / 2;
    win_cords->gox = (WIN_X - G_O_X) / 2;
    win_cords->sbx = (COLS + WIN_X) / 2 + 2;
}