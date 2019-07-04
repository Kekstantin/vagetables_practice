#include "bot.h"
#include "world.h"

void bot::move(float &time)
{
	this->setSpeedX(0.95*(this->getTarget().first->getX() - this->getX()) / (this->getWidthAndHeight()*this->getTarget().second));
	this->setSpeedY(0.95*(this->getTarget().first->getY() - this->getY()) / (this->getWidthAndHeight()*this->getTarget().second));


        this->setX(this->getX() + this->getSpeedX()*time);
        this->setY(this->getY() + this->getSpeedY()*time);
}

void bot::update(float &time)
{
	//move(time);
	this->sprite.setPosition(x, y);
}