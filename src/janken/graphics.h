#ifndef JANKEN_SRC_JANKEN_GRAPHICS_H
#define JANKEN_SRC_JANKEN_GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

typedef struct graphics {
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
} graphics_t;

graphics_t* graphics_create();
void graphics_destroy(graphics_t* graphics);

#endif // JANKEN_SRC_JANKEN_GRAPHICS_H
