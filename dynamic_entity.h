#pragma once
#include "static_entity.h"
class dynamic_entity :
	public entity
{
public:
	//const&destr
	dynamic_entity() {};
	dynamic_entity(sf::Texture &texture, sf::FloatRect &rect, speed_ speedX, speed_ speedY) : entity(texture, rect), speedX(speedX), speedY(speedY) 
	{
		widthAndHeight = rect.height;
		target = mp(nullptr, 0.0);
	}
	~dynamic_entity();

	//getters&setters
	void setSpeedX(speed_ speedX);
	void setSpeedY(speed_ speedY);
	void setTarget(std::pair<entity*, float> _target);
	speed_ getSpeedX() const;
	speed_ getSpeedY() const;
	std::pair<entity*, float> getTarget() const;


	//public methods
	virtual void move(float &time) = 0;		//Ìåòîä, çàäàþùèé äâèæåíèå äèíàìè÷åñêîé ñóùíîñòè
	virtual void update(float &time) = 0;		//Кость, это надо бы в обертку сунуть
	virtual void eat(entity* entityForEat);	
	
protected:
	float widthAndHeight;
	speed_ speedX;
	speed_ speedY;
	std::pair<entity*, float> target;
	//Òóò åùå öâåò áóäåò? Êîñòü, ëó÷øå ñóíü ýòî â îáåðòêó
};

