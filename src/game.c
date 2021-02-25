#include "janken/game.h"

game_t* game_create() {
    game_t* game = calloc(1, sizeof(game_t));
    game->m_graphics = graphics_create();
    game->m_quit = 0;

    return game;
}

void game_destroy(game_t* game) {
    graphics_destroy(game->m_graphics);
    free(game);
}

void events(game_t* game) {
    while(SDL_PollEvent(&game->m_event) != 0) {
        switch(game->m_event.type) {
            case SDL_QUIT: {
                game->m_quit = 1;
            } break;
        }
    }
}

void update(game_t* game) {
    if(game->m_quit) {
        SDL_Log("quitting...\n");
    }
}

void render(graphics_t* graphics) {
    SDL_RenderClear(graphics->m_renderer);
    SDL_RenderPresent(graphics->m_renderer);
}

void game_run(game_t* game) {
    while(!game->m_quit) {
        events(game);
        update(game);
        render(game->m_graphics);
    }
}
