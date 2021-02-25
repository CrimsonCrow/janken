#include "janken/game.h"

int init() {
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s\n", SDL_GetError());
        return 0; /* returns false */
    }

    int img_flags = IMG_INIT_JPG | IMG_INIT_PNG;
    if((IMG_Init(img_flags) & img_flags) != img_flags) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s\n", IMG_GetError());
        return 0;
    }

    return 1; /* returns true */
}

void quit() {
    IMG_Quit();
    SDL_Quit();
}

int main(void) {
    if(!init()) {
        return -1;
    } else {
        game_t* game = game_create();
        game_run(game);
        game_destroy(game);
    }

    quit();

    return 0;
}
