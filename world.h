#pragma once
#include "player.h"

class world
{
public:
	//const&destr
	world(sf::Texture &texture, sf::FloatRect &rect)
	{
		sprite.setTextureRect(sf::IntRect(rect.left, rect.top, widthAndHeight, widthAndHeight));
		sprite.setTexture(texture);
		sprite.setPosition(rect.left, rect.top);
	}
	~world();

	//getters&setters
	void setPlayer(player* _player);
	player* getPlayer() const;
	float getWidthAndHeight() const;
	std::map<std::pair<float, float>, static_entity*> get_collect_of_static_entitys() const;
	std::map<std::pair<float, float>, dynamic_entity*> get_collect_of_dynamic_entitys() const;

	//public methods
	void checkCollision(dynamic_entity* _dynamic_entity);
	void pushStaticEntity(static_entity* _entity);
	void pushDynamicEntity(dynamic_entity* _entity);
	bool removeStaticEntity(static_entity* _entity);
	bool removeDynamicEntity(dynamic_entity* _entity);
	void createEntity(type_ _type);
	void moveAllBot();
	virtual entity* find_target(bot* bot);

private:
	const float widthAndHeight = 10000.0;	//Òóò 10000 òîëüêî ÷òîáû ñîáèðàëîñü, õç ñêîëüêî òóò ïîñòàâèòü
	std::map<std::pair<float, float>, static_entity*> collect_of_static_entitys;
	std::map<std::pair<float, float>, dynamic_entity*> collect_of_dynamic_entitys;
	std::map<float, entity*> collect_of_sprites;//dobavit' push_back i remove
	player* _player;
	sf::Sprite sprite;
};
