#include "s21_frontend.h"

// ДЕЙСТВИЯ С ФИГУРАМИ И ПОЛЕМ

void s21_print_figure(WINDOW *w, Figure_t *fig_cur) {
    for (int i = 0; i < FIGURE_SIZE; i++) {
        for (int j = 0; j < FIGURE_SIZE; j++) {
            s21_set_color(w, fig_cur->type);
            if (fig_cur->shape[i][j])
                mvwaddch(w, fig_cur->cord.y + i, fig_cur->cord.x + j, F_CHAR);
            wattroff(w, A_BOLD | COLOR_PAIR(fig_cur->type + 1));
        }
    }
}

void s21_print_next_figure(WINDOW *w, Figure_t *fig_next) {
    werase(w);
    box(w, 0, 0);

    for (int i = 0; i < FIGURE_SIZE; i++) {
        for (int j = 0; j < FIGURE_SIZE; j++) {
            s21_set_color(w, fig_next->type);
            if (fig_next->shape[i][j])
                mvwaddch(w, 0 + i, (NEXT_X - FIGURE_SIZE) / 2 + j, F_CHAR);
            wattroff(w, A_BOLD | COLOR_PAIR(fig_next->type + 1));
        }
    }
    s21_fill_window(w, NEXT);
}

void s21_print_field(WINDOW *w, GameInfo_t *g_i) {
    for (int i = 0; i < WIN_X; i++) {
        for (int j = 0; j < WIN_Y; j++) {
            if (g_i->field[j][i]) mvwaddch(w, j, i, F_CHAR);
        }
    }
}

void s21_set_color(WINDOW *w, int f_index) {
    wattron(w, A_BOLD);
    switch (f_index) {
        case 0:
            wattron(w, COLOR_PAIR(1));
            break;
        case 1:
            wattron(w, COLOR_PAIR(2));
            break;
        case 2:
            wattron(w, COLOR_PAIR(3));
            break;
        case 3:
            wattron(w, COLOR_PAIR(4));
            break;
        case 4:
            wattron(w, COLOR_PAIR(5));
            break;
        case 5:
            wattron(w, COLOR_PAIR(6));
            break;
        case 6:
            wattron(w, COLOR_PAIR(7));
            break;
        default:
            wattron(w, COLOR_PAIR(1));
            break;
    }
}

// ДЕЙСТВИЯ С ПОЛЕМ

void s21_fill_window(WINDOW *w, ScreenType type) {
    const char *instr[] = {"START     R", "PAUSE     P", "QUIT      Q",
                           "LEFT      ",  "RIGHT     ",  "DOWN      ",
                           "ROTATE    ",  "DROP  SPACE", " HELP "};
    const char *game_over[] = {"GAME", "OVER"};
    const char *stat[] = {" STAT ", "RECORD", "LEVEL", "SCORE", "SPEED"};

    wattron(w, A_BOLD);
    switch (type) {
        case INSTR:
            mvwprintw(w, 0, (INSTR_X - 6) / 2, "%s", instr[8]);
            for (int i = 0; i < 8; i++) {
                mvwprintw(w, (i + 1) * 2, 2, "%s", instr[i]);

                if (i == 3) waddch(w, ACS_LARROW);
                if (i == 4) waddch(w, ACS_RARROW);
                if (i == 5) waddch(w, ACS_DARROW);
                if (i == 6) waddch(w, ACS_UARROW);
            }
            break;
        case GAME_OVER:
            for (int i = 0; i < 2; i++)
                mvwprintw(w, i + 1, (G_O_X - 4) / 2, "%s", game_over[i]);
            break;
        case PAUSE:
            mvwprintw(w, PAUSE_Y / 2, (PAUSE_X - 6) / 2, "%s", "PAUSED");
            break;
        case STAT:
            mvwprintw(w, 0, (STAT_X - 6) / 2, "%s", stat[0]);
            for (int i = 1; i < 5; i++)
                mvwprintw(w, (i * 3) - 1, 2, "%s", stat[i]);
            break;
        case NEXT:
            mvwprintw(w, 0, (NEXT_X - 6) / 2, " NEXT ");
            break;
        default:
            break;
    }
    wattroff(w, A_BOLD);
    wrefresh(w);
}

void s21_print_stat(WINDOW *w, GameInfo_t *g_i) {
    werase(w);
    box(w, 0, 0);

    mvwprintw(w, 2, 9, "%d", g_i->high_score);
    mvwprintw(w, 5, 9, "%d", g_i->level);
    mvwprintw(w, 8, 9, "%d", g_i->score);
    mvwprintw(w, 11, 9, "%d%%",
              abs(100 - ((MAX_FALL_DELAY_MS - g_i->speed) * 100 /
                         (MAX_FALL_DELAY_MS - MIN_FALL_DELAY_MS))));

    s21_fill_window(w, STAT);
}

void s21_show_window(WINDOW *w, ScreenType type) {
    wbkgd(w, 32);
    werase(w);
    wborder(w, 32, 32, 32, 32, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER,
            ACS_LRCORNER);
    s21_fill_window(w, type);

    if (type == GAME_OVER) getch();
}

void s21_set_subwindow(ScreenType *s_type, GameState_t state) {
    if (state == STATE_PAUSE) *s_type = PAUSE;
    if (state == STATE_GAME_OVER) *s_type = GAME_OVER;
}