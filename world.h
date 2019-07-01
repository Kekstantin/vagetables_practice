#pragma once
#include "player.h"

class world
{
public:
	//const&destr
	world();
	~world();

	//getters&setters
	void setPlayer(player* _player);
	player* getPlayer() const;
	std::map<std::pair<float, float>, static_entity*> get_collect_of_static_entitys() const;
	std::map<std::pair<float, float>, dynamic_entity*> get_collect_of_dynamic_entitys() const;

	//public methods
	void checkCollision();
	void pushStaticEntity(static_entity* _entity);
	void pushDynamicEntity(dynamic_entity* _entity);
	bool removeStaticEntity(static_entity* _entity);
	bool removeDynamicEntity(dynamic_entity* _entity);
	void createEntity(type_ _type);
	void moveAllBot() const;

private:
	const float widthAndHeight = 10000.0;	//Òóò 10000 òîëüêî ÷òîáû ñîáèðàëîñü, õç ñêîëüêî òóò ïîñòàâèòü
	std::map<std::pair<float, float>, static_entity*> collect_of_static_entitys;
	std::map<std::pair<float, float>, dynamic_entity*> collect_of_dynamic_entitys;
	player* _player;
};
