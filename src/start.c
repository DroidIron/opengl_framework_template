#include <SDL3/SDL.h>
#include <glad/glad.h>
#include <stdio.h>

#include "window.h"
#include "settings.h"

int start(void)
{
    printf("Hello, World!\n");

    // SDL:
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        printf("ERROR::SDL::Failed to initalize SDL: %s\n", SDL_GetError());
        return 1;
    }

    // GL attributes:
    SDL_GL_SetAttribute(GL_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(GL_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    // Window:
    if (create_window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT) != 0) {return 1;}
    Window *window = get_window();
    SDL_GL_MakeCurrent(window->sdl_window, window->context);
    SDL_SetWindowRelativeMouseMode(window->sdl_window, true);

    // Glad:
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        printf("ERROR::GLAD::Glad could not load: %s\n", glad_glGetError());
        return 1;
    }

    glViewport(0, 0, window->window_width, window->window_height);
    glEnable(GL_DEPTH_TEST);

    return 0;
}