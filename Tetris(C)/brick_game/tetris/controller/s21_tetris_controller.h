#ifndef S21_TETRIS_CONTROLLER
#define S21_TETRIS_CONTROLLER

#include "../s21_backend.h"
#include "stdbool.h"

typedef struct {
    GameState_t cur_state;
    UserAction_t cur_action;
    GameState_t next_state;
} Transition;

void userInput(UserAction_t action, bool hold);
GameInfo_t updateCurrentState();

#endif  //  S21_TETRIS_CONTROLLER