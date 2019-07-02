#include "static_entity.h"

float static_entity::getWidthAndHeight() const
{
	return widthAndHeight;
}

void static_entity::update(float &time)
{
	this->sprite.setPosition(x,y);
}
static_entity::~static_entity(){}
