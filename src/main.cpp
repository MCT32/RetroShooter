#include <stdio.h>
#include <SDL.h>

#include "render.hpp"
#include "map.hpp"
#include "player.hpp"

const struct Map map = {
	7,
	7,
	{
		1, 1, 1, 1, 1, 1, 1,
		1, 1, 0, 0, 0, 1, 1,
		1, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1
	}
};

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
	Player player = Player(Vec2(3.5, 3.5), 0.0);

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
					switch (event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							game_running = false;
							break;
					}
			}
		}

		// Draw code here
		draw_background(winSurface, (struct SDL_Color){255, 0, 0}, (struct SDL_Color){0, 255, 0}, (struct SDL_Color){0, 0, 255});

		draw_walls(winSurface, (struct SDL_Color){255, 255, 255}, &map, &player);

		SDL_UpdateWindowSurface(window);
	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
