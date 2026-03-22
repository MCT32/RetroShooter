#pragma once

#include "actor.hpp"
#include "vec.hpp"

class Player : public Actor {
	public:
	Player();

	Player(Vec2 pos, double angle);
};
