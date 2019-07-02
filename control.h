#pragma once
#include "C:\Users\ִלטענטי\source\repos\practice\practice\world.h"

using namespace sf;

std::list<FloatRect> bot_rect_list;
std::list<Sprite> bot_sprite_list;

void aaaa()
{
	Clock clock;
	float time = clock.getElapsedTime().asMicroseconds();
	clock.restart();
	time = time / 800;


	Texture world_texture;
	FloatRect world_rect(0, 0, 5000, 5000);
	world_texture.loadFromFile("images/world.png");

	Texture static_texture;
	FloatRect static_rect(0, 0, 5, 5);
	static_texture.loadFromFile("images/static.png");


	Texture bot_texture;
	FloatRect bot_rect(0, 0, 10, 10);
	bot_texture.loadFromFile("images/bot.png");


	Texture player_texture;
	FloatRect player_rect(0, 0, 15, 15);
	player_texture.loadFromFile("images/player.png");


	world _world(world_texture, world_rect);
	static_entity static1(static_texture, static_rect);//list of static entity
	bot b1(bot_texture, bot_rect, 1.0 / bot_rect.height, 1.0 / bot_rect.height);//listOfBots
	player _player(player_texture, player_rect, 1.0 / player_rect.height, 1.0 / player_rect.height);


}