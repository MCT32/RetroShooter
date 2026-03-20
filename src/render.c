#include "render.h"

void set_pixel(SDL_Surface* surface, unsigned int x, unsigned int y, SDL_Color color)
{
    if (x >= surface->w || y >= surface->h)
    {
        return;
    }

    unsigned int formatted_color = SDL_MapRGB(surface->format, color.r, color.g, color.b);

    memcpy(surface->pixels + x * surface->format->BytesPerPixel + y * surface->pitch, &formatted_color, sizeof(formatted_color));
}

void draw_hline(SDL_Surface* surface, unsigned int x, unsigned int y, unsigned int l, SDL_Color color)
{
    if (x >= surface->w || y >= surface->h)
    {
        return;
    }

    unsigned int formatted_color = SDL_MapRGB(surface->format, color.r, color.g, color.b);

    // TODO: Prevent overdraw spilling to next row
    for (int i = 0; i < l; i++)
    {
        memcpy(surface->pixels + (x + i) * surface->format->BytesPerPixel + y * surface->pitch, &formatted_color, sizeof(formatted_color));
    }
}

void draw_vline(SDL_Surface* surface, unsigned int x, unsigned int y, unsigned int l, SDL_Color color)
{
    if (x >= surface->w || y >= surface->h)
    {
        return;
    }

    unsigned int formatted_color = SDL_MapRGB(surface->format, color.r, color.g, color.b);

    for (int i = 0; i < l; i++)
    {
        memcpy(surface->pixels + x * surface->format->BytesPerPixel + (y + i) * surface->pitch, &formatted_color, sizeof(formatted_color));
    }
}

void draw_background(SDL_Surface* surface, SDL_Color floor, SDL_Color horizon, SDL_Color ceiling)
{
    for (int i = 0; i < surface->h; i++)
    {
        double factor = 2.0 * ((double)i / (double)surface->h);

        SDL_Color color;
        if (factor < 1.0)
        {
            color = lerp_color(fmod(factor, 1.0), floor, horizon);
        }
        else
        {
            color = lerp_color(fmod(factor, 1.0), horizon, ceiling);
        }

        draw_hline(surface, 0, i, surface->w, color);
    }
}

void draw_walls(SDL_Surface* surface, SDL_Color color, struct Map* map, struct Player* player)
{
    double screenratio = (double)surface->w / (double)surface->h;

    for (int i = 0; i < surface->w; i++)
    {
        vec2 dir;
        dir.x = ((((double)i / (double)surface->w) * 2.0) - 1.0);

        double length = sqrt((dir.x * dir.x) + 1);

        dir.x = dir.x / length;
        dir.y = 1.0 / length;

        dir = rotate_vec2(dir, player->angle);

        double dist = raycast(map, player->pos, dir, 20.0);
        double dist_corrected = dist / length;
        unsigned int height = (unsigned int)(surface->h / dist_corrected);

        unsigned int start = (surface->h - height) / 2;

        SDL_Color shaded = map_color(dist, 2.0, 4.0, (struct SDL_Color){255, 255, 255}, (struct SDL_Color){0, 0, 0});

        draw_vline(surface, i, start, height, shaded);
    }
}
