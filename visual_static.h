#pragma once
#include "visual_world.h"

//Otpravit' v control
/*Texture static_texture;
FloatRect static_rect(0, 0, getwidthAndHeight(), getwidthAndHeight());
Sprite static_sprite;

static_texture.loadFromFile("images/static.png");
static_sprite.setTexture(static_texture);
static_sprite.setOrigin(getwidthAndHeight() / 2, getwidthAndHeight() / 2);*/


sf::Sprite draw_static()
{
	for (auto obj : static_list)
	{
		static_rect.left = &obj->getX();
		static_rect.top = &obj->getY();
		static_rect.width = &obj->getWidthAndHeight();
		static_rect.height = &obj->getWidthAndHeight();
		&obj->update(time);
	}

	static_sprite.setPosition(static_rect.left, static_rect.top);
	return static_sprite;
}