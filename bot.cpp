#include "bot.h"
#include "world.h"

void bot::move(float &time, std::pair<entity*, float> target)
{
	this->setSpeedX(0.2*(target.first->getX() - this->getX()) / (this->getWidthAndHeight()*target.second));
	this->setSpeedX(0.2*(target.first->getY() - this->getY()) / (this->getWidthAndHeight()*target.second));


        this->setX(this->getSpeedX()*time);
        this->setY(this->getSpeedY()*time);
}

void bot::update(float &time, std::pair<entity*, float> target)
{
	move(time, target);
	this->sprite.setPosition(x, y);
}