#pragma once
#include "C:\Users\ƒмитрий\source\repos\practice\practice\world.h"

using namespace sf;

std::list<FloatRect> bot_rect_list;
std::list<Sprite> bot_sprite_list;

void initialization(sf::RenderWindow* window)
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


	world _world(world_texture, world_rect, bot_texture, bot_rect, static_texture, static_rect);
	_world.set_static_rect(static_rect);
	_world.set_bot_rect(bot_rect);
	_world.set_static_texture(static_texture);
	_world.set_bot_texture(bot_texture);
	static_entity static1(static_texture, static_rect);//list of static entity
	bot b1(bot_texture, bot_rect, 0.141, 0.141);//listOfBots
	player _player(player_texture, player_rect, 0, 0);//плееру не нужна начальна€ скорость

	_world.push_collect_of_sprites(static1.getWidthAndHeight(), &static1);
	_world.push_collect_of_sprites(b1.getWidthAndHeight(), &b1);
	_world.push_collect_of_sprites(_player.getWidthAndHeight(), &_player);

	_world.moveAllBot(time);
	for (auto obj : _world.get_collect_of_sprites())
		window->draw(obj.second->getSprite());
}