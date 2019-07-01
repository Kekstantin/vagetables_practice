#pragma once
#include "world.h"
#include <SFML/Graphics.hpp>

//Otpravit' v control
/*Texture world_texture;
FloatRect world_rect(0, 0, getwidthAndHeight(), getwidthAndHeight());
Sprite world_sprite;

world_texture.loadFromFile("images/world.png");
world_sprite.setTexture(world_texture);
world_sprite.setOrigin(getwidthAndHeight() / 2, getwidthAndHeight() / 2);*/


sf::Sprite draw_world()
{

	world_sprite.setPosition(world_rect.left, world_rect.top);
	return world_sprite;
}