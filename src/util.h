#ifndef UTIL_H
#define UTIL_H

#include <SDL.h>
#include "map.h"
#include "vec.h"

SDL_Color lerp_color(double factor, SDL_Color color1, SDL_Color color2);

SDL_Color map_color(double factor, double min, double max, SDL_Color color1, SDL_Color color2);

double raycast(struct Map* map, vec2 start, vec2 dir, double maxdist);

#endif
