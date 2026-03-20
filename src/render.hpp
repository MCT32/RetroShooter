#pragma once

#include <SDL.h>
#include <math.h>
#include "util.hpp"
#include "map.hpp"
#include "player.hpp"
#include "vec.hpp"

void draw_background(SDL_Surface* surface, SDL_Color floor, SDL_Color horizon, SDL_Color ceiling);

void draw_walls(SDL_Surface* surface, SDL_Color color, const struct Map* map, struct Player* player);
