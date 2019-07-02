#include "entity.h"

void entity::setX(coord_ x)
{
	this->x = x;
}

void entity::setY(coord_ y)
{
	this->y = y;
}

coord_ entity::getX() const
{
	return x;
}

coord_ entity::getY() const
{
	return y;
}

float entity::getWidthAndHeight() const
{
	return widthAndHeight;
}

void entity::setWidthAndHeight(float widthAndHeight)
{
	this->widthAndHeight = widthAndHeight;
}

entity::~entity(){}
