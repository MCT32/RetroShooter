#include <stdio.h>
#include <SDL.h>

#include "render.h"

int main(int argc, char* argv[])
{
    SDL_Surface* winSurface = NULL;
    SDL_Window* window = NULL;

    if (SDL_Init( SDL_INIT_EVERYTHING ) < 0)
    {
        printf("Error initialising SDL2: %s\n", SDL_GetError());

        return 1;
    }

    window = SDL_CreateWindow("RetroShooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

    if (!window)
    {
        printf("Error creating window: %s\n", SDL_GetError());

        return 1;
    }

    winSurface = SDL_GetWindowSurface( window );

    if (!winSurface)
    {
        printf("Error getting window surface: %s\n", SDL_GetError());

        return 1;
    }

    bool game_running = true;

    // Game loop
    while (game_running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    game_running = false;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        game_running = false;
                        break;
                    }
            }
        }

        // Draw code here
        draw_background(winSurface, (struct SDL_Color){255, 0, 0}, (struct SDL_Color){0, 255, 0}, (struct SDL_Color){0, 0, 255});

        SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
