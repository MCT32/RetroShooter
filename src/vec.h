#ifndef VEC_H
#define VEC_H

#include <math.h>

typedef struct vec2 {
    double x;
    double y;
} vec2;

typedef struct ivec2 {
    int x;
    int y;
} ivec2;

ivec2 vec2_to_ivec2(vec2 vector);

vec2 rotate_vec2(vec2 vector, double rads);

#endif
