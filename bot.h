#pragma once
#include "dynamic_entity.h"
class bot :
	public dynamic_entity
{
public:
	//const&destr
	bot();
	~bot();

	//public methods
	// Óíàñëåäîâàíî ÷åðåç dynamic_entity
	virtual void move(const world* _world) override;
	virtual void update() override;
};

