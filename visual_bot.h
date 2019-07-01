#pragma once
#include "visual_static.h"

//Otpravit' v control
/*Texture bot_texture;
FloatRect bot_rect(0, 0, getwidthAndHeight(), getwidthAndHeight());
Sprite bot_sprite;

bot_texture.loadFromFile("images/bot.png");
bot_sprite.setTexture(bot_texture);
bot_sprite.setOrigin(getwidthAndHeight() / 2, getwidthAndHeight() / 2);*/


sf::Sprite draw_bot()
{
	for (auto obj : bot_list)
	{
		bot_rect.left = &obj->getX();
		bot_rect.top = &obj->getY();
		bot_rect.width = &obj->getWidthAndHeight();
		bot_rect.height = &obj->getWidthAndHeight();
		&obj->update(time);
	}

	bot_sprite.setPosition(bot_rect.left, bot_rect.top);
	return bot_sprite;
}