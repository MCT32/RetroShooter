#include <stdio.h>
#include <unistd.h>
#include <SDL.h>

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

    // Draw code here
    SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 255, 0, 255));

    SDL_UpdateWindowSurface(window);

    sleep(10);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
