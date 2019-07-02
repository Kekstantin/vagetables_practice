#pragma once
#include "dynamic_entity.h"
class bot :
	public dynamic_entity
{
public:
	//const&destr
	bot() {};
	bot(sf::Texture &texture, sf::FloatRect &rect, speed_ speedX, speed_ speedY) : dynamic_entity(texture, rect, speedX, speedY) {}
	~bot();

	//public methods
	// Унаследовано через dynamic_entity
	virtual void move(float &time, entity* target) override;
	virtual void update(float &time, entity* target) override;
};

