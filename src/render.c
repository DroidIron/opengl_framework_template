#include <glad/glad.h>
#include <SDL3/SDL.h>

#include "window.h"

void render(void)
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Window *window = get_window();
    
    // Render code here:

    

    // -----------------

    SDL_GL_SwapWindow(window->sdl_window);
}