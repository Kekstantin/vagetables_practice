#include "world.h"

void world::setPlayer(player * _player)
{
	this->_player = _player;
}

player * world::getPlayer()
{
	return _player;
}

float world::getWidthAndHeight() const
{
	return widthAndHeight;
}

std::map<std::pair<float, float>, static_entity*> world::get_collect_of_static_entitys() const
{
	return collect_of_static_entitys;
}

std::map<std::pair<float, float>, dynamic_entity*> world::get_collect_of_dynamic_entitys() const
{
	return collect_of_dynamic_entitys;
}

std::map<float, entity*> world::get_collect_of_sprites() const
{
	return collect_of_sprites;
}

sf::Texture world::get_static_texture()
{
	return static_texture;
}

sf::Texture world::get_bot_texture()
{
	return bot_texture;
}

sf::FloatRect world::get_static_rect()
{
	return static_rect;
}

sf::FloatRect world::get_bot_rect()
{
	return bot_rect;
}

void world::set_static_texture(sf::Texture static_texture)
{
	this->static_texture = static_texture;
}

void world::set_bot_texture(sf::Texture bot_texture)
{
	this->bot_texture = bot_texture;
}

void world::set_static_rect(sf::FloatRect static_rect)
{
	this->static_rect = static_rect;
}

void world::set_bot_rect(sf::FloatRect bot_rect)
{
	this->bot_rect = bot_rect;
}

void world::checkCollision(dynamic_entity* _dynamic_entity)
{
	for (auto obj : collect_of_dynamic_entitys) {
		bool pointOneX = obj.first.first >= _dynamic_entity->getX() && obj.first.first <= _dynamic_entity->getX() + _dynamic_entity->getWidthAndHeight();
		bool pointOneY = obj.first.second <= _dynamic_entity->getY() && obj.first.second >= _dynamic_entity->getY() - _dynamic_entity->getWidthAndHeight();
		bool pointTwoX = obj.first.first + obj.second->getWidthAndHeight() >= _dynamic_entity->getX() && obj.first.first + obj.second->getWidthAndHeight() >= _dynamic_entity->getX() + _dynamic_entity->getWidthAndHeight();
		bool pointTwoY = obj.first.second - obj.second->getWidthAndHeight() <= _dynamic_entity->getY() && obj.first.second - obj.second->getWidthAndHeight() >= _dynamic_entity->getY() - obj.second->getWidthAndHeight();
		
		if (pointOneX && pointOneY && pointTwoX && pointTwoY){
			_dynamic_entity->eat(obj.second);
			this->removeDynamicEntity(obj.second);
		}
	}
	//zavtra obsudim
}

void world::pushStaticEntity(static_entity * _entity)
{
	collect_of_static_entitys.insert(mp(mp(_entity->getX(), _entity->getY()), _entity));
}

void world::pushDynamicEntity(dynamic_entity * _entity)
{
	collect_of_dynamic_entitys.insert(mp(mp(_entity->getX(), _entity->getY()), _entity));
}

bool world::removeStaticEntity(static_entity * _entity)
{
	auto _iter = collect_of_static_entitys.find(mp(_entity->getX(), _entity->getY()));

	if (_iter == collect_of_static_entitys.end())
		return false;
	else {
		collect_of_static_entitys.erase(_iter);
		return true;
	}
}

bool world::removeDynamicEntity(dynamic_entity * _entity)
{
	auto _iter = collect_of_dynamic_entitys.find(mp(_entity->getX(), _entity->getY()));

	if (_iter == collect_of_dynamic_entitys.end())
		return false;
	else {
		collect_of_dynamic_entitys.erase(_iter);
		return true;
	}
}

void world::push_collect_of_sprites(float widthAndHeight, entity * _entity)
{
	collect_of_sprites.insert(mp(widthAndHeight, _entity));
}

bool world::remove_collect_of_sprites(float widthAndHeight, entity * _entity)
{
	auto _iter = collect_of_sprites.find(widthAndHeight);

	if (_iter == collect_of_sprites.end())
		return false;
	else {
		collect_of_sprites.erase(_iter);
		return true;
	}
}

void world::moveAllBot(float time)
{
	this->checkCollision(this->getPlayer());

	for (auto obj : collect_of_dynamic_entitys) {
		obj.second->update(time, (this->find_target(obj.second)));
		//obj.first = mp(obj.second->getX(), obj.second->getY());
		auto tmp = collect_of_dynamic_entitys.extract(obj.first);
		tmp.key() = mp(obj.second->getX(), obj.second->getY());
		collect_of_dynamic_entitys.insert(move(tmp));
		this->checkCollision(obj.second);
	}
}

std::pair<entity*, float> world::find_target(dynamic_entity* _bot)
{
	float distance = sqrt((this->get_collect_of_static_entitys().begin()->first.first - _bot->getX()) *
		(this->get_collect_of_static_entitys().begin()->first.first - _bot->getX()) +
		(this->get_collect_of_static_entitys().begin()->first.second - _bot->getY()) *
		(this->get_collect_of_static_entitys().begin()->first.second - _bot->getY()));
	float new_distance;
	entity* target = this->get_collect_of_static_entitys().begin()->second;
	auto result = mp(target, distance);
	
	for (auto i : this->get_collect_of_static_entitys())
	{
		new_distance = distance;
		if ((_bot->getWidthAndHeight() / i.second->getWidthAndHeight()) > 1.2) {
			new_distance = sqrt((i.first.first - _bot->getX()) *
				(i.first.first - _bot->getX()) +
				(i.first.second - _bot->getY()) *
				(i.first.second - _bot->getY()));
		}
		if (new_distance < distance) {
			distance = new_distance;
			target = i.second;
		}
	}
	for (auto i : this->get_collect_of_dynamic_entitys())
	{
		new_distance = distance;
		if ((_bot->getWidthAndHeight() / i.second->getWidthAndHeight()) > 1.2) {
			new_distance = sqrt((i.first.first - _bot->getX()) *
				(i.first.first - _bot->getX()) +
				(i.first.second - _bot->getY()) *
				(i.first.second - _bot->getY()));
		}
                auto xtime = (_bot->getX()-i.second->getX())/(i.second->getSpeedX()-_bot->getSpeedX());
                auto ytime = (_bot->getY()-i.second->getY())/(i.second->getSpeedY()-_bot->getSpeedY());
                if ((new_distance < distance) && (xtime>0) && (ytime>0)) {
			distance = new_distance;
			target = i.second;
		}
				
	}
	return result;
}

void world::create_method() {

	std::mt19937 gen(time(NULL));
	std::uniform_int_distribution<> uid(0, 5000);                 //todo define magic numbers

	while (this->get_collect_of_dynamic_entitys().size() < 50) {       //todo define magic numbers
		float perem_x = uid(gen);
		float perem_y = uid(gen);

		bool is_point_for_spawn_is_good1 = perem_x > this->getPlayer()->getX() + 1366 / 2;
		bool is_point_for_spawn_is_good2 = perem_x < this->getPlayer()->getX() - 1366 / 2;
		bool is_point_for_spawn_is_good3 = perem_y > this->getPlayer()->getY() + 768 / 2;
		bool is_point_for_spawn_is_good4 = perem_y < this->getPlayer()->getY() - 768 / 2;

		if (is_point_for_spawn_is_good1 || is_point_for_spawn_is_good2 || is_point_for_spawn_is_good3 || is_point_for_spawn_is_good4)                                            //tut nuzno znat razmer okna blyat
			this->get_collect_of_dynamic_entitys().emplace(mp(mp(perem_x, perem_y), new bot(bot_texture, bot_rect, 0.141, 0.141)));  //need getters   //todo define magic numbers
	}

	while (this->get_collect_of_static_entitys().size() < 300) {         //todo define magic numbers
		float perem_x = uid(gen);
		float perem_y = uid(gen);

		bool is_point_for_spawn_is_good1 = perem_x > this->getPlayer()->getX() + 1366 / 2;
		bool is_point_for_spawn_is_good2 = perem_x < this->getPlayer()->getX() - 1366 / 2;
		bool is_point_for_spawn_is_good3 = perem_y > this->getPlayer()->getY() + 768 / 2;
		bool is_point_for_spawn_is_good4 = perem_y < this->getPlayer()->getY() - 768 / 2;

		if (is_point_for_spawn_is_good1 || is_point_for_spawn_is_good2 || is_point_for_spawn_is_good3 || is_point_for_spawn_is_good4)                                            //tut nuzno znat razmer okna blyat
			this->get_collect_of_static_entitys().emplace(mp(mp(perem_x, perem_y), new static_entity(static_texture, static_rect)));//need getters
	}

}