#include "vec.hpp"

Vec2::Vec2()
{
	this->x = 0.0;
	this->y = 0.0;
}

Vec2::Vec2(double x, double y)
{
	this->x = x;
	this->y = y;
}

IVec2 Vec2::toIVec2()
{
	return IVec2((int)x, (int)y);
}

Vec2 Vec2::rotate(double rads)
{
	return Vec2(
		x * cos(rads) - y * sin(rads),
		x * sin(rads) + y * cos(rads)
	);
}

IVec2::IVec2()
{
	this->x = 0;
	this->y = 0;
};

IVec2::IVec2(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vec2 IVec2::toVec2()
{
	return Vec2((int)x, (int)y);
}
