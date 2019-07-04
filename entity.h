#pragma once
#include "list_of_type.h"

class entity
{
public:
	//const&destr
	entity() {};
	entity(sf::Texture &texture, sf::FloatRect &rect) //perepisat' konstructori u ostalnih entity 
	{
	    entity_rect = rect;
		x = rect.left;
		y = rect.top;
		widthAndHeight = rect.width;
		sprite.setTextureRect(sf::IntRect(rect.left, rect.top, widthAndHeight, widthAndHeight)); 
		sprite.setTexture(texture); 
	}
	~entity();

	//getters&setters
	void setY(coord_ coordinate);
	void setX(coord_ coordinate);
	coord_ getY() const;
	coord_ getX() const;
	sf::FloatRect getRect();
	void setWidthAndHeight(float widthAndHeight);
	float getWidthAndHeight() const;
	sf::Sprite getSprite() const;
    sf::Sprite sprite;//getter nado napista'
    sf::FloatRect entity_rect;
protected:

	coord_ x;
	float widthAndHeight;
	coord_ y;
};

