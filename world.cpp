#include "world.h"

world::world(){}

world::~world(){}

void world::setPlayer(player * _player)
{
	this->_player = _player;
}

player * world::getPlayer() const
{
	return _player;
}

std::map<std::pair<float, float>, static_entity*> world::get_collect_of_static_entitys() const
{
	return collect_of_static_entitys;
}

std::map<std::pair<float, float>, dynamic_entity*> world::get_collect_of_dynamic_entitys() const
{
	return collect_of_dynamic_entitys;
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

void world::createEntity(type_ _type)
{
		//zdes budut sozdavatysa elementy 
}

void world::moveAllBot() const
{
	this->checkCollision(this->getPlayer());

	for (auto obj : collect_of_dynamic_entitys) {
		obj.second->move(); // возмножно в скобках что то будет
		this->checkCollision(obj.second);
	}
}

entity* world::find_target(bot* _bot)
{
	float distance = sqrt((this->get_collect_of_static_entitys().begin().first().first() - _bot->getX()) *
		(this->get_collect_of_static_entitys().begin().first().first() - _bot->getX()) +
		(this->get_collect_of_static_entitys().begin().first().second() - _bot->getY()) *
		(this->get_collect_of_static_entitys().begin().first().second() - _bot->getY()));
	float new_distance;
	auto target = this->get_collect_of_static_entitys().begin().second();
	for (auto i : this->get_collect_of_static_entitys())
	{
		new_distance = distance;
		if ((_bot->getWidthAndHeight() / i.second()->getWidthAndHeight()) > 1.2) {
			new_distance = sqrt((i.begin().first().first() - _bot->getX()) *
				(i.begin().first().first() - _bot->getX()) +
				(i.begin().first().second() - _bot->getY()) *
				(i.begin().first().second() - _bot->getY()));
		}
		if (new_distance < distance) {
			distance = new_distance;
			target = i.second;
		}
	}
	for (auto i : this->get_collect_of_dynamic_entitys())
	{
		new_distance = distance;
		if ((_bot->getWidthAndHeight() / i.second()->getWidthAndHeight()) > 1.2) {
			new_distance = sqrt((i.begin().first().first() - _bot->getX()) *
				(i.begin().first().first() - _bot->getX()) +
				(i.begin().first().second() - _bot->getY()) *
				(i.begin().first().second() - _bot->getY()));
		}
		if (new_distance < distance) {
			distance = new_distance;
			target = i.second;
		}
	}
	return target;
}
