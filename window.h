#pragma once

#include <SDL3/SDL.h>

typedef struct
{
    char *title;
    unsigned int window_width;
    unsigned int window_height;

    SDL_Window *sdl_window;
    SDL_GLContext context;
} Window;

int create_window(char *title, unsigned int width, unsigned int height);
void cleanup_window(void);
Window *get_window(void);
void resize_window(unsigned int new_width, unsigned int new_height);