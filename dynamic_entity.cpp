#include "dynamic_entity.h"

void dynamic_entity::setSpeedX(speed_ speedX)
{
	this->speedX = speedX;
}
void dynamic_entity::setSpeedY(speed_ speedY)
{
	this->speedY = speedY;
}

speed_ dynamic_entity::getSpeedX() const
{
	return speedX;
}
speed_ dynamic_entity::getSpeedY() const
{
	return speedY;
}


void dynamic_entity::eat(entity * entityForEat)
{
    float tmp = this->getWidthAndHeight();
	this->setWidthAndHeight(this->getWidthAndHeight() + 8.0/(this->getWidthAndHeight()-entityForEat->getWidthAndHeight()));
    sprite.setTextureRect(sf::IntRect(entity_rect.left, entity_rect.top, entity_rect.height, entity_rect.height));
	//this->getSprite().scale(this->getWidthAndHeight()/tmp,this->getWidthAndHeight()/tmp);
}


void dynamic_entity::update(float &time)
{
	//move(time, target);
	this->sprite.setPosition(x, y);
}

void dynamic_entity::setTarget(std::pair<entity*, float> _target)
{
	this->target.first = _target.first;
	this->target.second = _target.second;
}

std::pair<entity*, float> dynamic_entity::getTarget() const
{
	auto result = mp(this->target.first, this->target.second);
	return result;
}

dynamic_entity::~dynamic_entity(){}
