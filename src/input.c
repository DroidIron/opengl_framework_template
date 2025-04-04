#include <SDL3/SDL.h>
#include <stdbool.h>

#include "window.h"

static SDL_Event event;

bool input(void)
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_EVENT_QUIT:
                return false;
                break;
            case SDL_EVENT_WINDOW_RESIZED:
                resize_window(event.window.data1, event.window.data2);
                break;
            case SDL_EVENT_KEY_DOWN:
                switch (event.key.scancode)
                {
                    case SDL_SCANCODE_ESCAPE:
                        return false;
                        break;
                    
                    default:
                        break;
                }
                break;
        }
    }

    return true;
}