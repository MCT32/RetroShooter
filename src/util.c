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
