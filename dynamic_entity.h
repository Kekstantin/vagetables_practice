#pragma once
#include "static_entity.h"
class dynamic_entity :
	public entity
{
public:
	//const&destr
	dynamic_entity(float widthAndHeight, speed_ speedX, speed_ speedY);
	~dynamic_entity();

	//getters&setters
	void setSpeedX(speed_ speedX);
	void setSpeedY(speed_ speedY);
	void setWidthAndHeight(float widthAndHeight);
	speed_ getSpeedX() const;
	speed_ getSpeedY() const;
	float getWidthAndHeight() const;

	//public methods
	virtual void move() = 0;		//Ìåòîä, çàäàþùèé äâèæåíèå äèíàìè÷åñêîé ñóùíîñòè
	virtual void update() = 0;		//Кость, это надо бы в обертку сунуть
	virtual void eat(dynamic_entity* entityForEat);	
	
private:
	float widthAndHeight;
	speed_ speedX;
	speed_ speedY;
	//Òóò åùå öâåò áóäåò? Êîñòü, ëó÷øå ñóíü ýòî â îáåðòêó
};

