#ifndef RENDER_H
#define RENDER_H

#include <SDL.h>
#include <math.h>
#include "util.h"
#include "map.h"
#include "player.h"
#include "vec.h"

void draw_background(SDL_Surface* surface, SDL_Color floor, SDL_Color horizon, SDL_Color ceiling);

void draw_walls(SDL_Surface* surface, SDL_Color color, struct Map* map, struct Player* player);

#endif
