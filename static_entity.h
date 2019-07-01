#pragma once
#include "entity.h"
class static_entity :
	public entity
{
public:
	//const&destr
	static_entity();
	~static_entity();

	//public methods
	float getWidthAndHeight() const;

private:
	const float widthAndHeight = 10.0;	//Я тут поставил 10 только чтобы оно собиралось
};

