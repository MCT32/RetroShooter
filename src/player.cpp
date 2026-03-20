#include "player.hpp"

Player::Player()
{
	this->pos = Vec2(2.0, 2.0);
	this->angle - 0.0;
}

Player::Player(Vec2 pos, double angle)
{
	this->pos = pos;
	this->angle = angle;
}
