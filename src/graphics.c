#include "janken/graphics.h"

graphics_t* graphics_create() {
    graphics_t* grap = calloc(1, sizeof(graphics_t));
    grap->m_window = SDL_CreateWindow("Janken", SDL_WINDOWPOS_CENTERED,
                                      SDL_WINDOW_POPUP_MENU, SCREEN_WIDTH,
                                      SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(grap->m_window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s\n", SDL_GetError());
        return grap;
    }

    grap->m_renderer = SDL_CreateRenderer(grap->m_window, -1,
                                          SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    if(grap->m_renderer == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s\n", SDL_GetError());
        return grap;
    }

    SDL_SetRenderDrawColor(grap->m_renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);

    return grap;
}

void graphics_destroy(graphics_t *graphics) {
    SDL_DestroyRenderer(graphics->m_renderer);
    SDL_DestroyWindow(graphics->m_window);
    free(graphics);
}
