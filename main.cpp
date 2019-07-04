#include "control.h"

void menu(sf::RenderWindow &window)
{
	sf::Texture menu_background_texture, start_button_texture, exit_button_texture;
	menu_background_texture.loadFromFile("images/menu.png");
	start_button_texture.loadFromFile("images/start_button.png");
	exit_button_texture.loadFromFile("images/exit_button.png");
	sf::Sprite menu_background(menu_background_texture), start_button(start_button_texture), exit_button(exit_button_texture);
	bool is_menu = 1;
	int menu_num;
	menu_background.setPosition(0, 0);
	start_button.setPosition(260, 100);
	exit_button.setPosition(320, 220);

	while (is_menu)
	{
		start_button.setColor(sf::Color::White);
		exit_button.setColor(sf::Color::White);
		menu_num = 0;
		window.clear(sf::Color(12, 12, 12));

		if (sf::IntRect(260, 100, 285, 79).contains(sf::Mouse::getPosition(window))) { start_button.setColor(sf::Color::Red); menu_num = 1; }
		if (sf::IntRect(320, 220, 155, 80).contains(sf::Mouse::getPosition(window))) { exit_button.setColor(sf::Color::Red); menu_num = 2; }

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menu_num == 1) is_menu = false;
			if (menu_num == 2) { window.close(); is_menu = false; }
		}

		window.draw(menu_background);
		window.draw(start_button);
		window.draw(exit_button);

		window.display();
	}
}

bool start_game()
{
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1366, 768), "square-io", Style::Default, settings);

	menu(window);

	std::list<FloatRect> bot_rect_list;
	std::list<Sprite> bot_sprite_list;
	Clock clock;



	Texture world_texture;
	FloatRect world_rect(0, 0, 2333, 2333);
	world_texture.loadFromFile("images/world.jpg");

	Texture static_texture;
	FloatRect static_rect(50, 50, 5, 5);
	static_texture.loadFromFile("images/static.png");


	Texture bot_texture;
	FloatRect bot_rect(200, 200, 10, 10);
	bot_texture.loadFromFile("images/bot.png");


	Texture player_texture;
	FloatRect player_rect(600, 800, 15, 15);
	player_texture.loadFromFile("images/player.png");

	Texture lose_texture;
	lose_texture.loadFromFile("images/lose.png");
	Sprite lose_sprite(lose_texture);

	Texture win_texture;
	win_texture.loadFromFile("images/win.png");
	Sprite win_sprite(win_texture);

	player _player(player_texture, player_rect, 0.141, 0.141);//������ �� ����� ��������� ��������
	_player.view.reset(sf::FloatRect(0, 0, 1366, 768));

	world _world(world_texture, world_rect, bot_texture, bot_rect, static_texture, static_rect, &_player);
	_world.set_static_rect(static_rect);
	_world.set_bot_rect(bot_rect);
	_world.set_static_texture(static_texture);
	_world.set_bot_texture(bot_texture);
	static_entity static1(static_texture, static_rect);//list of static entity
	bot b1(bot_texture, bot_rect, 0.241, 0.241);//listOfBots

	_world.pushDynamicEntity(&b1);
	_world.pushStaticEntity(&static1);

	_world.push_collect_of_sprites(&static1);
	_world.push_collect_of_sprites(&b1);
	_world.push_collect_of_sprites(&_player);


	int tempX = 0;
	int tempY = 0;
	float distance = 0;


	////******/////

	std::mt19937 gen(time(NULL));
	std::uniform_int_distribution<> uid(0, 2333);                 //todo define magic numbers

	while (_world.get_collect_of_dynamic_entitys().size() < 50) {       //todo define magic numbers
		float perem_x = uid(gen);
		float perem_y = uid(gen);

		/*bool is_point_for_spawn_is_good1 = perem_x > _world.getPlayer()->getX() + 1366 / 2;
		bool is_point_for_spawn_is_good2 = perem_x < _world.getPlayer()->getX() - 1366 / 2;
		bool is_point_for_spawn_is_good3 = perem_y > _world.getPlayer()->getY() + 768 / 2;
		bool is_point_for_spawn_is_good4 = perem_y < _world.getPlayer()->getY() - 768 / 2;

		if (is_point_for_spawn_is_good1 || is_point_for_spawn_is_good2 || is_point_for_spawn_is_good3 || is_point_for_spawn_is_good4)   */                                         //tut nuzno znat razmer okna blyat

		//_world.get_collect_of_dynamic_entitys().emplace(mp(mp(perem_x, perem_y), new bot(bot_texture, bot_rect, 0.141, 0.141)));  //need getters   //todo define magic numbers
		sf::FloatRect this_bot_rect(perem_x, perem_y, 10, 10);
		bot* tmp_obj = new bot(bot_texture, this_bot_rect, 0.0, 0.0);
		_world.push_collect_of_sprites(tmp_obj);
		_world.pushDynamicEntity(tmp_obj);
		/*_world.push_collect_of_sprites(&_player);*/

	}

	while (_world.get_collect_of_static_entitys().size() < 900) {         //todo define magic numbers
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

	_world.sort_list_of_sprites();

	///******////



	while (window.isOpen())
	{
		float time1 = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time1 = time1 / 800;

		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				_player.setSpeedX(0.15);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				_player.setSpeedX(-0.15);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				_player.setSpeedY(-0.15);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				_player.setSpeedY(0.15);
			}
			

			if (event.type == sf::Event::Closed)
				window.close();
			/*
						if (event.type == sf::Event::MouseMoved)
						{
							if (event.mouseButton.button == sf::Mouse::Left)
							{
								_player.isMove = true;
								tempX = pos.x;
								tempY = pos.y;
								if (_player.isMove)
								{
									distance = sqrt((tempX - _player.getX())*(tempX - _player.getX()) + (tempY - _player.getY())*(tempY - _player.getY()));
									if (distance > 30)
									{
										_player.setX(_player.getX() + _player.getSpeedX()*time1*(tempX - _player.getX()) / distance);
										_player.setY(_player.getY() + _player.getSpeedY()*time1*(tempY - _player.getY()) / distance);
									}
									else _player.isMove = false;
								}

							}
						}*/
		}

		_world.moveAllBot(time1);

		for (auto obj : _world.get_collect_of_dynamic_entitys())
			obj.second->update(time1);

		for (auto obj : _world.get_collect_of_static_entitys())
			obj.second->update(time1);

		_player.update(time1);

		window.setView(_player.view);
		window.clear();

		window.draw(_world.getSprite());
		for (auto obj : _world.get_collect_of_sprites())
			window.draw(obj.second->getSprite());

		if (_world.getPlayer()->getWidthAndHeight() == 0) 
		{
			lose_sprite.setPosition(_player.view.getCenter().x - 1366/2, _player.view.getCenter().y - 768 / 2);/*vmesto etoi stroki napishi 4to proishodit v sluchae smerti igroka*/
			window.draw(lose_sprite);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) return true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) return false;

		}

		if (_world.get_collect_of_dynamic_entitys().size() <= 1) 
		{
			win_sprite.setPosition(_player.view.getCenter().x - 1366 / 2, _player.view.getCenter().y - 768 / 2);/*vmesto etoi stroki napishi 4to proishodit v sluchae pobedi igroka*/
			window.draw(win_sprite);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) return false;
		}

		window.display();
	}

	return 0;
}

void game_running()
{
	if (start_game()) { game_running(); }
}

int main()
{
	game_running();
	return 0;
}