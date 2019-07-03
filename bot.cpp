#include "bot.h"
#include "world.h"

void bot::move(float &time)
{
	this->setSpeedX(0.2*(this->getTarget().first->getX() - this->getX()) / (this->getWidthAndHeight()*this->getTarget().second));
	this->setSpeedX(0.2*(this->getTarget().first->getY() - this->getY()) / (this->getWidthAndHeight()*this->getTarget().second));


        this->setX(this->getSpeedX()*time);
        this->setY(this->getSpeedY()*time);
}

void bot::update(float &time)
{
	//move(time);
	this->sprite.setPosition(x, y);
}