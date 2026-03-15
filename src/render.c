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

void draw_background(SDL_Surface* surface, SDL_Color floor, SDL_Color horizon, SDL_Color ceiling)
{
    for (int i = 0; i < surface->h; i++)
    {
        double factor = 2.0 * ((double)i / (double)surface->h);

        SDL_Color color;
        if (factor < 1.0)
        {
            color = lerp_color(fmod(factor, 1.0), floor, horizon);
        } else {
            color = lerp_color(fmod(factor, 1.0), horizon, ceiling);
        }

        draw_hline(surface, 0, i, surface->w, color);
    }
}
