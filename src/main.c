// Third-party:
#include <glad/glad.h>
#include <SDL3/SDL.h>
#include <cglm/cglm.h>

#include <stdio.h>
#include <stdbool.h>

#include "start.h"
#include "input.h"
#include "render.h"
#include "update.h"
#include "cleanup.h"

static bool game_running = true;

static Uint64 current_frame = 0;
Uint64 last_frame = 0;
double delta_time = 0;
// double seconds = 0;

int main(int argc, char *argv[])
{
    if (start() != 0) {return 1;}

    current_frame = SDL_GetPerformanceCounter();

    while (game_running)
    {
        // Delta time:
        last_frame = current_frame;
        current_frame = SDL_GetPerformanceCounter();
        delta_time = (double)((current_frame - last_frame) * 1000 / (double)SDL_GetPerformanceFrequency());
        // seconds += delta_time * 0.001;
        // printf("%f\n", seconds);

        game_running = input();
        render();
        update();
    }

    cleanup();

    return 0;
}