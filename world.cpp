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

void world::checkCollision()
{
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
	for (auto obj : collect_of_dynamic_entitys)
		obj.second->move(this);
}
