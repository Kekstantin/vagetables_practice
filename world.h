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

	//public methods
	void checkCollision();
	void pushEntity(entity* _entity, type_ _type);
	bool removeEntity(entity* _entity, type_ _type);
	void createEntity(type_ _type);
	void moveAllBot() const;

private:
	const float widthAndHeight = 10000.0;	//Òóò 10000 òîëüêî ÷òîáû ñîáèðàëîñü, õç ñêîëüêî òóò ïîñòàâèòü
	std::map<std::pair<float, float>, static_entity*> collectOfStaticEnemys;
	std::map<std::pair<float, float>, dynamic_entity*> collectOfDynamicEnemys;
	player* _player;
};

