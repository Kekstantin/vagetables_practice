#pragma once
#include "control.h"


sf::Sprite draw_world()
{
	world_sprite.setPosition(world_rect.left, world_rect.top);
	return world_sprite;
}