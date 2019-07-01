#include "entity.h"

entity::entity(coord_ x, coord_ y) 
{
	this->x = x;
	this->y = y;
}

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

entity::~entity(){}
