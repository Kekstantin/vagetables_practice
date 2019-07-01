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
	// Унаследовано через dynamic_entity
	virtual void move() override;
	virtual void update() override;
};

