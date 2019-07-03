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
	}
	~dynamic_entity();

	//getters&setters
	void setSpeedX(speed_ speedX);
	void setSpeedY(speed_ speedY);
	speed_ getSpeedX() const;
	speed_ getSpeedY() const;


	//public methods
	virtual void move(float &time, std::pair<entity*, float> target) = 0;		//Ìåòîä, çàäàþùèé äâèæåíèå äèíàìè÷åñêîé ñóùíîñòè
	virtual void update(float &time, std::pair<entity*, float> target) = 0;		//Кость, это надо бы в обертку сунуть
	virtual void eat(entity* entityForEat);	
	
private:
	float widthAndHeight;
	speed_ speedX;
	speed_ speedY;
	//Òóò åùå öâåò áóäåò? Êîñòü, ëó÷øå ñóíü ýòî â îáåðòêó
};

