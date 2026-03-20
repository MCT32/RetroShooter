#pragma once

#include <math.h>

// Forward declarations
class Vec2;
class IVec2;

class Vec2 {
	public:
	double x;
	double y;

	Vec2();
	Vec2(double x, double y);

	IVec2 toIVec2();

	Vec2 rotate(double rads);
};

class IVec2 {
	public:
	int x;
	int y;

	IVec2();
	IVec2(int x, int y);

	Vec2 toVec2();
};
