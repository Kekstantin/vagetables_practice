#include "C:\Users\ƒмитрий\source\repos\KVADRAT_IO\Project10\control.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "square-io");
	
	std::list<FloatRect> bot_rect_list;
	std::list<Sprite> bot_sprite_list;
		Clock clock;
		float time1 = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time1 = time1 / 800;


		Texture world_texture;
		FloatRect world_rect(0, 0, 5000, 5000);
		world_texture.loadFromFile("images/world.jpg");

		Texture static_texture;
		FloatRect static_rect(50, 50, 5, 5);
		static_texture.loadFromFile("images/static.png");


		Texture bot_texture;
		FloatRect bot_rect(200, 200, 10, 10);
		bot_texture.loadFromFile("images/bot.png");


		Texture player_texture;
		FloatRect player_rect(300, 200, 15, 15);
		player_texture.loadFromFile("images/player.png");

		player _player(player_texture, player_rect, 0, 0);//плееру не нужна начальна€ скорость

		world _world(world_texture, world_rect, bot_texture, bot_rect, static_texture, static_rect, &_player);
		_world.set_static_rect(static_rect);
		_world.set_bot_rect(bot_rect);
		_world.set_static_texture(static_texture);
		_world.set_bot_texture(bot_texture);
		static_entity static1(static_texture, static_rect);//list of static entity
		bot b1(bot_texture, bot_rect, 0.141, 0.141);//listOfBots

		_world.pushDynamicEntity(&b1);
		_world.pushStaticEntity(&static1);

		_world.push_collect_of_sprites(&static1);
		_world.push_collect_of_sprites(&b1);
		_world.push_collect_of_sprites(&_player);



		////******/////

		std::mt19937 gen(time(NULL));
		std::uniform_int_distribution<> uid(0, 5000);                 //todo define magic numbers

		while (_world.get_collect_of_dynamic_entitys().size() < 1500) {       //todo define magic numbers
			float perem_x = uid(gen);
			float perem_y = uid(gen);

			/*bool is_point_for_spawn_is_good1 = perem_x > _world.getPlayer()->getX() + 1366 / 2;
			bool is_point_for_spawn_is_good2 = perem_x < _world.getPlayer()->getX() - 1366 / 2;
			bool is_point_for_spawn_is_good3 = perem_y > _world.getPlayer()->getY() + 768 / 2;
			bool is_point_for_spawn_is_good4 = perem_y < _world.getPlayer()->getY() - 768 / 2;

			if (is_point_for_spawn_is_good1 || is_point_for_spawn_is_good2 || is_point_for_spawn_is_good3 || is_point_for_spawn_is_good4)   */                                         //tut nuzno znat razmer okna blyat
	
			//_world.get_collect_of_dynamic_entitys().emplace(mp(mp(perem_x, perem_y), new bot(bot_texture, bot_rect, 0.141, 0.141)));  //need getters   //todo define magic numbers
			sf::FloatRect this_bot_rect(perem_x, perem_y, 10, 10);
			bot* tmp_obj = new bot(bot_texture, this_bot_rect, 0.141, 0.141);
			_world.push_collect_of_sprites(tmp_obj);
			_world.pushDynamicEntity(tmp_obj);
			/*_world.push_collect_of_sprites(&_player);*/

		}

		while (_world.get_collect_of_static_entitys().size() < 520) {         //todo define magic numbers
			float perem_x = uid(gen);
			float perem_y = uid(gen);

			/*bool is_point_for_spawn_is_good1 = perem_x > _world.getPlayer()->getX() + 1366 / 2;
			bool is_point_for_spawn_is_good2 = perem_x < _world.getPlayer()->getX() - 1366 / 2;
			bool is_point_for_spawn_is_good3 = perem_y > _world.getPlayer()->getY() + 768 / 2;
			bool is_point_for_spawn_is_good4 = perem_y < _world.getPlayer()->getY() - 768 / 2;

			if (is_point_for_spawn_is_good1 || is_point_for_spawn_is_good2 || is_point_for_spawn_is_good3 || is_point_for_spawn_is_good4)   */    
			//tut nuzno znat razmer okna blyat
			
			sf::FloatRect this_static_rect(perem_x, perem_y, 5, 5);
			static_entity* tmp_obj = new static_entity(static_texture, this_static_rect);
			_world.push_collect_of_sprites(tmp_obj);
			_world.pushStaticEntity(tmp_obj);//need getters

		}

		///******////

		

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		for (auto obj : _world.get_collect_of_dynamic_entitys())
			obj.second->update(time1);

		for (auto obj : _world.get_collect_of_static_entitys())
			obj.second->update(time1);

		_player.update(time1);
		window.clear();

		window.draw(_world.getSprite());
		for (auto obj : _world.get_collect_of_sprites())
			window.draw(obj.second->getSprite());
		window.display();
	}

	return 0;
}