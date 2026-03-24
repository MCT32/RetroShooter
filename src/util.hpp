#pragma once

#include <SDL.h>
#include "map.hpp"
#include "vec.hpp"
#include "defines.hpp"
#include "actor.hpp"

SDL_Color lerp_color(double factor, SDL_Color color1, SDL_Color color2);

SDL_Color map_color(double factor, double min, double max, SDL_Color color1, SDL_Color color2);

double raycast(const struct Map* map, Vec2 start, Vec2 dir, double maxdist);

unsigned int add_to_edict(Actor* edict[], Actor* actor);
