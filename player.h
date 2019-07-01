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
	// Óíàñëåäîâàíî ÷åðåç dynamic_entity
	virtual void move(const world* _world) override;
	virtual void update() override;
};

