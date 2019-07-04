#pragma once
#include "visual_static.h"

std::list<sf::Sprite> draw_bot(std::map<std::pair<float, float>, dynamic_entity*> bot_list)
{
	for (auto obj : bot_list)
	{
		for (auto obj1 : bot_rect_list)
		{
			obj1.left = obj.second->getX();
			obj1.top = obj.second->getY();
			obj1.width = obj.second->getWidthAndHeight();
			obj1.height = obj.second->getWidthAndHeight();
			for (auto obj2 : bot_sprite_list)
			{
				obj2.setOrigin(obj.second->getWidthAndHeight() / 2, obj.second->getWidthAndHeight() / 2);
				obj2.setPosition(obj1.left, obj1.top);
			}
		}
	}
	return bot_sprite_list;
}