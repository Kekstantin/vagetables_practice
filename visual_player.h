#pragma once
#include "C:\Users\ִלטענטי\source\repos\practice\practice\visual_bot.h"


sf::Sprite draw_player(world* _world)
{
	_world->getPlayer()->update(time);
	player_sprite.setPosition(player_rect.left, player_rect.top);
	return player_sprite;
}