#include "static_entity.h"

static_entity::static_entity(const float widthAndHeight):entity(x,y)
{
	this->widthAndHeight = widthAndHeight;
}

float static_entity::getWidthAndHeight() const
{
	return widthAndHeight;
}
static_entity::~static_entity(){}
