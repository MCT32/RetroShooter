#include "vec.h"

ivec2 vec2_to_ivec2(vec2 vector)
{
	ivec2 result = {(int)floor(vector.x), (int)floor(vector.y)};
	return result;
}

vec2 rotate_vec2(vec2 vector, double rads)
{
	vec2 result = {
		vector.x * cos(rads) - vector.y * sin(rads),
		vector.x * sin(rads) + vector.y * cos(rads)
	};
	return result;
}
