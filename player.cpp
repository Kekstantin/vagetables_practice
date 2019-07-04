#include "player.h"

player::~player(){}


void player::move(float &time)
{
	/*if (x < 0) { x = 0; speedX = 0; speedY = 0; }
	if (y < 0) { y = 0; speedX = 0; speedY = 0; }
	if (x > 2333) { x = 2333; speedX = 0; speedY = 0; }
	if (y > 2333) { y = 2333; speedX = 0; speedY = 0; }*/
	entity_rect.left += this->speedX*time;
	x += this->speedX*time;
	speedX = 0;
	entity_rect.top += this->speedY*time;
	y += this->speedY*time;
	speedY = 0;
	set_coordinate_for_view(x, y);

}

void player::update(float &time)
{
	move(time);
	this->sprite.setPosition(x, y);
}
