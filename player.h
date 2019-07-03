#pragma once
#include "bot.h"
class player :
	public dynamic_entity
{
public:
	sf::View view;

	void set_coordinate_for_view(double x, double y)
	{
		double tempX = x; double tempY = y;
		if (x < 683) tempX = 683;
		if (x >= 4317) tempX = 4317;
		if (y < 384) tempY = 384;
		if (y >= 4616) tempY = 4616;

		view.setCenter(tempX, tempY);
	}
	
	bool isMove = false;
	//const&destr
	player() {};
	player(sf::Texture &texture, sf::FloatRect &rect, speed_ speedX, speed_ speedY) : dynamic_entity(texture, rect, speedX, speedY) {}
	~player();

	//public methods
	// Óíàñëåäîâàíî ÷åðåç dynamic_entity
	void move(float &time);
	void update(float &time);
};

