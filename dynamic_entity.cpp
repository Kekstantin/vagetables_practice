#include "dynamic_entity.h"

dynamic_entity::dynamic_entity(float widthAndHeight, speed_ speedX, speed_ speedY;) :entity(x, y)
{
	this->widthAndHeight = widthAndHeight;
	this->speedX = speedX;
	this->speedY = speedY;
}

void dynamic_entity::setSpeedX(speed_ speedX)
{
	this->speedX = speedX;
}
void dynamic_entity::setSpeedY(speed_ speedY)
{
	this->speedY = speedY;
}
void dynamic_entity::setWidthAndHeight(float widthAndHeight)
{
	this->widthAndHeight = widthAndHeight;
}
speed_ dynamic_entity::getSpeedX() const
{
	return speedX;
}
speed_ dynamic_entity::getSpeedY() const
{
	return speedY;
}
float dynamic_entity::getWidthAndHeight() const
{
	return widthAndHeight;
}
