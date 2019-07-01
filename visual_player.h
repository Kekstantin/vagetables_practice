#pragma once
#include "visual_bot.h"

//Otpravit' v control
/*Texture player_texture;
FloatRect player_rect(0, 0, getwidthAndHeight(), getwidthAndHeight());
Sprite player_sprite;

player_texture.loadFromFile("images/player.png");
player_sprite.setTexture(player_texture);
player_sprite.setOrigin(getwidthAndHeight() / 2, getwidthAndHeight() / 2);*/


sf::Sprite draw_player()
{
	
	player_sprite.setPosition(player_rect.left, player_rect.top);
	return bot_sprite;
}
