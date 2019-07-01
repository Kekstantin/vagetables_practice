#pragma once
#include "list_of_type.h"

class entity
{
public:
	//const&destr
	entity();
	~entity();

	//getters&setters
	void setY(coord_ coordinate);
	void setX(coord_ coordinate);
	coord_ getY() const;
	coord_ getX() const;

private:
	coord_ x;
	coord_ y;
};

