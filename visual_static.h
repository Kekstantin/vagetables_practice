#pragma once
#include "visual_world.h"




std::list<sf::Sprite> draw_static(std::map<std::pair<float, float>, static_entity*> _static_list)
{
	for (auto obj : _static_list)
	{								///todo
		static_rect.left = obj.getX();
		static_rect.top = obj.getY();
		static_rect.width = obj.getWidthAndHeight();
		static_rect.height = obj.getWidthAndHeight();
		static_sprite.setPosition(static_rect.left, static_rect.top);
	}
	return static_list;
}