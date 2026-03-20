#include "util.h"

SDL_Color lerp_color(double factor, SDL_Color color1, SDL_Color color2)
{
	return (struct SDL_Color)
	{
		color1.r * (1.0 - factor) + color2.r * factor,
		color1.g * (1.0 - factor) + color2.g * factor,
		color1.b * (1.0 - factor) + color2.b * factor,
		color1.a * (1.0 - factor) + color2.a * factor,
	};
}

SDL_Color map_color(double factor, double min, double max, SDL_Color color1, SDL_Color color2)
{
	if (factor <= min) return color1;
	if (factor >= max) return color2;

	double real_factor = (factor - min) / (max - min);

	return lerp_color(real_factor, color1, color2);
}

double raycast(struct Map* map, vec2 start, vec2 dir, double maxdist)
{
	// Distance ray has to travel to cross a cell in each direction
	vec2 delta = {
		sqrt(1 + (dir.y / dir.x) * (dir.y / dir.x)),
		sqrt(1 + (dir.x / dir.y) * (dir.x / dir.y))
	};

	// Currently checked cell
	ivec2 mappos = vec2_to_ivec2(start);

	vec2 length;	// Distance traveled to edge of cell in each direction
	ivec2 step;		// Direction to step cells

	if (dir.x < 0)
	{
		step.x = -1;
		length.x = (start.x - (double)mappos.x) * delta.x;
	}
	else
	{
		step.x = 1;
		length.x = ((double)mappos.x + 1 - start.x) * delta.x;
	}

	if (dir.y < 0)
	{
		step.y = -1;
		length.y = (start.y - (double)mappos.y) * delta.y;
	}
	else
	{
		step.y = 1;
		length.y = ((double)mappos.y + 1 - start.y) * delta.y;
	}

	bool hit = false;
	double dist = 0.0;
	while (!hit && dist < maxdist) {
		if (length.x < length.y)
		{
			mappos.x += step.x;
			dist = length.x;
			length.x += delta.x;
		}
		else
		{
			mappos.y += step.y;
			dist = length.y;
			length.y += delta.y;
		}

		if (map->walls[mappos.x + mappos.y * map->w] > 0)
		{
			hit = true;
		}
	}

	vec2 intercept;
	if (hit)
	{
		intercept.x = start.x + dir.x * dist;
		intercept.y = start.y + dir.y * dist;
	}

	return dist;
}
