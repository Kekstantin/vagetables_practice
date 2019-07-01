#pragma once
#include "bot.h"
class player :
	public dynamic_entity
{
public:
	//const&destr
	player();
	~player();

	//public methods
	// Унаследовано через dynamic_entity
	virtual void move() override;
	virtual void update() override;
};

