#include "player.h"

player::~player(){}


void player::move(float & time, entity * target)
{
}

void player::update(float &time, entity * target)
{
	move(time, target);
	this->sprite.setPosition(x, y);
}
