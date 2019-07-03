#include "player.h"

player::~player(){}


void player::move(float &time)
{
}

void player::update(float &time)
{
	//move(time, target);
	this->sprite.setPosition(x, y);
}
