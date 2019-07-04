#include "player.h"

player::~player(){}


void player::move(float &time)
{
    entity_rect.left += this->speedX*time;
    x+=this->speedX*time;
    speedX = 0;
    entity_rect.top += this->speedY*time;
    y+=this->speedY*time;
    speedY = 0;
	set_coordinate_for_view(x, y);
}

void player::update(float &time)
{
	move(time);
	this->sprite.setPosition(x, y);
}
