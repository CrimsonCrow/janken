#ifndef JANKEN_SRC_JANKEN_GAME_H
#define JANKEN_SRC_JANKEN_GAME_H

#include "graphics.h"

typedef struct game {
    graphics_t* m_graphics;

    SDL_Event m_event;
    int m_quit;
} game_t;

game_t* game_create();
void game_destroy(game_t* game);

void game_run();

#endif // JANKEN_SRC_JANKEN_GAME_H
