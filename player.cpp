#include "player.h"

player::~player(){}


void player::move(float &time)
{
	set_coordinate_for_view(x, y);
}

void player::update(float &time)
{
	move(time);
	this->sprite.setPosition(x, y);
}
