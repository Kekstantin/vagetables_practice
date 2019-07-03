#pragma once
#include "player.h"

class world
{
public:
	//const&destr
	world() {}
	world(sf::Texture &texture, sf::FloatRect &rect, sf::Texture &bot_texture, sf::FloatRect &bot_rect, sf::Texture &static_texture, sf::FloatRect &static_rect, player* _player) : _player(_player)
	{
		world_texture = texture;
		world_rect = rect;
		this->bot_texture = bot_texture;
		this->bot_rect = bot_rect;
		this->static_texture = static_texture;
		this->static_rect = static_rect;
		world_sprite.setTextureRect(sf::IntRect(rect.left, rect.top, widthAndHeight, widthAndHeight));
		world_sprite.setTexture(texture);
		world_sprite.setPosition(rect.left, rect.top);
	}
	~world() {};

	//getters&setters
	void setPlayer(player* _player);
	player* getPlayer();
	float getWidthAndHeight() const;
	std::map<std::pair<float, float>, static_entity*> get_collect_of_static_entitys() const;
	std::map<std::pair<float, float>, dynamic_entity*> get_collect_of_dynamic_entitys() const;
	std::list<std::pair<float, entity*>> get_collect_of_sprites() const;
	sf::Texture get_static_texture();
	sf::Texture get_bot_texture();
	sf::FloatRect get_static_rect();
	sf::FloatRect get_bot_rect();
	sf::Sprite getSprite();
	void set_static_texture(sf::Texture static_texture);
	void set_bot_texture(sf::Texture bot_texture);
	void set_static_rect(sf::FloatRect static_rect);
	void set_bot_rect(sf::FloatRect bot_rect);



	//public methods
	void checkCollision(dynamic_entity* _dynamic_entity);
	void pushStaticEntity(static_entity* _entity);
	void pushDynamicEntity(dynamic_entity* _entity);
	bool removeStaticEntity(static_entity* _entity);
	bool removeDynamicEntity(dynamic_entity* _entity);
	void push_collect_of_sprites(entity* _entity);
	bool remove_collect_of_sprites(float widthAndHeight, entity* _entity);
	void moveAllBot(float time);
	void create_method();
	virtual std::pair<entity*, float> find_target(dynamic_entity* bot);

private:
	const float widthAndHeight = 5000.0;
	std::map<std::pair<float, float>, static_entity*> collect_of_static_entitys;
	std::map<std::pair<float, float>, dynamic_entity*> collect_of_dynamic_entitys;
	std::list<std::pair<float, entity*>> collect_of_sprites;//dobavit' push_back i remove
	player* _player;
	sf::Sprite world_sprite;
	sf::Texture world_texture;
	sf::FloatRect world_rect;
	sf::Texture static_texture;
	sf::FloatRect static_rect;
	sf::Texture bot_texture;
	sf::FloatRect bot_rect;
	
};
