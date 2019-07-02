#pragma once
#include "list_of_type.h"

class entity
{
public:
	//const&destr
	entity() {};
	entity(sf::Texture &texture, sf::FloatRect &rect) : x(rect.left), y(rect.top)//perepisat' konstructori u ostalnih entity 
	{ 
		sprite.setTextureRect(sf::IntRect(rect.left, rect.top, widthAndHeight, widthAndHeight)); 
		sprite.setTexture(texture); 
	}
	~entity();

	//getters&setters
	void setY(coord_ coordinate);
	void setX(coord_ coordinate);
	coord_ getY() const;
	coord_ getX() const;
	void setWidthAndHeight(float widthAndHeight);
	float getWidthAndHeight() const;

protected:
	sf::Sprite sprite;//getter nado napista'

	coord_ x;
	float widthAndHeight;
	coord_ y;
};

