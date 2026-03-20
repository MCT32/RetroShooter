#pragma once

#include "vec.hpp"

class Player {
	public:
	Vec2 pos;
	double angle;

	Player();

	Player(Vec2 pos, double angle);
};
