#include "bot.h"
#include "world.h"

bot::bot():dynamic_entity(float widthAndHeight, speed_ speedX, speed_ speedY) : entity(x, y) {}

entity* bot::find_target(world* _world)
{
	float distance = sqrt((_world->get_collect_of_static_entitys().begin().first().first() - this->getX()) *
		(_world->get_collect_of_static_entitys().begin().first().first() - this->getX()) +
		(_world->get_collect_of_static_entitys().begin().first().second() - this->getY()) *
		(_world->get_collect_of_static_entitys().begin().first().second() - this->getY()));
	float new_distance;
	auto target = _world->get_collect_of_static_entitys().begin().second();
	for (auto i : _world->get_collect_of_static_entitys())
	{
		new_distance = distance;
		if ((this->getWidthAndHeight() / i.second()->getWidthAndHeight()) > 1.2) {
			new_distance = sqrt((i.begin().first().first() - this->getX()) *
				(i.begin().first().first() - this->getX()) +
				(i.begin().first().second() - this->getY()) *
				(i.begin().first().second() - this->getY()));
		}
		if (new_distance < distance) {
			distance = new_distance;
			target = i.second;
		}
	}
	for (auto i : _world->get_collect_of_dynamic_entitys())
	{
		new_distance = distance;
		if ((this->getWidthAndHeight() / i.second()->getWidthAndHeight()) > 1.2) {
			new_distance = sqrt((i.begin().first().first() - this->getX()) *
				(i.begin().first().first() - this->getX()) +
				(i.begin().first().second() - this->getY()) *
				(i.begin().first().second() - this->getY()));
		}
		if (new_distance < distance) {
			distance = new_distance;
			target = i.second;
		}
	}
	return target;
}

void bot::move(world _world) 
{
	auto target = this->find_target(_world);
	//ôèã çíàåò ÷òî òóò äàëüøå 
}
