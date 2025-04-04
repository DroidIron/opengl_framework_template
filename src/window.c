#include <glad/glad.h>
#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "window.h"

static Window *window = NULL;

void cleanup_window(void);

int create_window(char *title, unsigned int width, unsigned int height)
{
    window = malloc(sizeof(Window));
    if (!window)
    {
        printf("ERROR::MEM::Could not allocate memory for the window\n");
        return 1;
    }

    window->sdl_window = SDL_CreateWindow(
        title,
        width, height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
    );
    if (!window->sdl_window)
    {
        printf("ERROR::SDL::Could not create the SDL window: %s\n", SDL_GetError());
        cleanup_window();
        return 1;
    }

    window->context = SDL_GL_CreateContext(window->sdl_window);
    if (!window->context)
    {
        printf("ERROR::SDL::Could not create the GL context: %s\n", SDL_GetError());
        cleanup_window();
        return 1;
    }

    window->title = title;
    window->window_width = width;
    window->window_height = height;

    return 0;
}

void cleanup_window(void)
{
    if (window)
    {
        if (window->context)
        {
            SDL_GL_DestroyContext(window->context);
        }
        if (window->sdl_window)
        {
            SDL_DestroyWindow(window->sdl_window);
        }

        free(window);
        window = NULL;
    }
}

Window *get_window(void)
{
    if (window)
    {
        return window;
    }
    else
    {
        printf("ERROR::WINDOW::Could not get window\n");
        return NULL;
    }
}

void resize_window(unsigned int new_width, unsigned int new_height)
{
    if (window)
    {
        window->window_width = new_width;
        window->window_height = new_height;

        glViewport(0, 0, window->window_width, window->window_height);

        printf("Window resized to x: %i y: %i\n", window->window_width, window->window_height);
    }
    else
    {
        printf("ERROR::WINDOW::Could not resize window\n");
    }
}