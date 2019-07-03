#pragma once
#include "bot.h"
class player :
	public dynamic_entity
{
public:
	//const&destr
	player() {};
	player(sf::Texture &texture, sf::FloatRect &rect, speed_ speedX, speed_ speedY) : dynamic_entity(texture, rect, speedX, speedY) {}
	~player();

	//public methods
	// Óíàñëåäîâàíî ÷åðåç dynamic_entity
	void move(float &time, std::pair<entity*, float> target);
	void update(float &time, std::pair<entity*, float> target);
};

