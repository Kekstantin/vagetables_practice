#include "entity.h"

void entity::setX(coord_ x)
{
	this->x = x;
	entity_rect.left = this-> x;
}

void entity::setY(coord_ y)
{
	this->y = y;
	entity_rect.top = this->y;
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

sf::Sprite entity::getSprite() const
{
	return sprite;
}

void entity::setWidthAndHeight(float widthAndHeight)
{
	this->widthAndHeight = widthAndHeight;
	entity_rect.width = this->widthAndHeight;
	entity_rect.height = this->widthAndHeight;
}

entity::~entity(){}

sf::FloatRect entity::getRect()
{
    return entity_rect;
}
