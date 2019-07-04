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

std::list<std::pair<std::pair<float, float>, static_entity*>> world::get_collect_of_static_entitys() const
{
	return collect_of_static_entitys;
}

std::list<std::pair<std::pair<float, float>, dynamic_entity*>> world::get_collect_of_dynamic_entitys() const
{
	return collect_of_dynamic_entitys;
}

std::list<std::pair<float, entity*>> world::get_collect_of_sprites() const
{
	return collect_of_sprites;
}

void world::sort_list_of_sprites(){
    collect_of_sprites.sort();
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

sf::Sprite world::getSprite()
{
	return world_sprite;
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
	/*for (auto obj : collect_of_dynamic_entitys) {
		bool pointOneX = obj.first.first >= _dynamic_entity->getX() && obj.first.first <= _dynamic_entity->getX() + _dynamic_entity->getWidthAndHeight();
		bool pointOneY = obj.first.second <= _dynamic_entity->getY() && obj.first.second >= _dynamic_entity->getY() - _dynamic_entity->getWidthAndHeight();
		bool pointTwoX = obj.first.first + obj.second->getWidthAndHeight() >= _dynamic_entity->getX() && obj.first.first + obj.second->getWidthAndHeight() >= _dynamic_entity->getX() + _dynamic_entity->getWidthAndHeight();
		bool pointTwoY = obj.first.second - obj.second->getWidthAndHeight() <= _dynamic_entity->getY() && obj.first.second - obj.second->getWidthAndHeight() >= _dynamic_entity->getY() - obj.second->getWidthAndHeight();
		
		if (pointOneX && pointOneY && pointTwoX && pointTwoY){
			_dynamic_entity->eat(obj.second);
			this->removeDynamicEntity(obj.second);
		}
	}*/

	for (auto obj : collect_of_sprites)
    {
	    if(_dynamic_entity != obj.second)
	    if (obj.second->getRect().intersects(_dynamic_entity->getRect()) && _dynamic_entity->getWidthAndHeight() > obj.second->getWidthAndHeight()){
	        _dynamic_entity->eat(obj.second);
	        //_dynamic_entity->eat(obj.second);
            dynamic_entity* tmp_for_delete = static_cast<dynamic_entity*>(obj.second);
            this->remove_collect_of_sprites(obj.first, obj.second);
            this->removeDynamicEntity(tmp_for_delete);
            tmp_for_delete->setWidthAndHeight(0);
            //delete obj.second;
            break;
	    }
    }

}

void world::pushStaticEntity(static_entity * _entity)
{
    this->collect_of_static_entitys.push_back(mp(mp(_entity->getX(), _entity->getY()), _entity));
}

void world::pushDynamicEntity(dynamic_entity * _entity)
{
	this->collect_of_dynamic_entitys.push_back(mp(mp(_entity->getX(), _entity->getY()), _entity));
}

void world::removeStaticEntity(static_entity * _entity)
{
    collect_of_static_entitys.remove(mp(mp(_entity->getX(), _entity->getY()), _entity));
}

void world::removeDynamicEntity(dynamic_entity * _entity)
{
	collect_of_dynamic_entitys.remove(mp(mp(_entity->getX(), _entity->getY()), _entity));
}

void world::push_collect_of_sprites(entity* _entity)
{
	this->collect_of_sprites.push_back(mp(_entity->getWidthAndHeight(), _entity));
	//this->collect_of_sprites[_entity->getWidthAndHeight()] = _entity;
}

void world::remove_collect_of_sprites(float widthAndHeight, entity * _entity)
{

    collect_of_sprites.remove(mp(widthAndHeight, _entity));

}

void world::moveAllBot(float time)
{
	this->checkCollision(this->getPlayer());

	for (auto obj : collect_of_dynamic_entitys) {
        this->find_target(obj.second);
		obj.second->move(time);
        this->checkCollision(obj.second);

        obj = mp(mp(obj.second->getX(), obj.second->getY()), obj.second);
    }

}

//std::pair<entity*, float>
void world::find_target(dynamic_entity* _bot)
{
	float distance = sqrt((this->getPlayer()->getX() - _bot->getX()) *
		(this->getPlayer()->getX() - _bot->getX()) +
		(this->getPlayer()->getY() - _bot->getY()) *
		(this->getPlayer()->getY() - _bot->getY()));
	float new_distance;
	entity* target = this->getPlayer();
	std::pair<entity*, float> result; //= mp(target, distance);
	
	for (auto i : this->get_collect_of_sprites())
	{
		new_distance = distance;
		if ((_bot->getWidthAndHeight() / i.second->getWidthAndHeight()) > 1.2) {
			new_distance = sqrt((i.second->getX() - _bot->getX()) *
                                (i.second->getX() - _bot->getX()) +
                                (i.second->getY() - _bot->getY()) *
                                (i.second->getY() - _bot->getY()));
		}
		if (new_distance < distance) {
			distance = new_distance;
			target = i.second;
		}
	}
	/*for (auto i : this->get_collect_of_dynamic_entitys())
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
				
	}*/
	result = mp(target, distance);
	_bot->setTarget(result);
	
	//return result;
}

/*void world::create_method() {

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

}*/