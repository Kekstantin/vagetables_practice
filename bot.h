#pragma once
#include "dynamic_entity.h"
class bot :
	public dynamic_entity
{
public:
	//const&destr
	bot() {};
	bot(coord_ x, coord_ y, speed_ speedX, speed_ speedY, float widthAndHeight) : dynamic_entity(x, y, speedX, speedY, widthAndHeight) {}
	~bot();

	//public methods
	// Унаследовано через dynamic_entity
	virtual void move(float time, entity target) override;
	//virtual void update() override;
};

