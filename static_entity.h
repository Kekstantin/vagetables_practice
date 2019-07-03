#pragma once
#include "entity.h"
class static_entity :
	public entity
{
public:
	//const&destr
	static_entity() {}
	static_entity(sf::Texture &texture, sf::FloatRect &rect) : entity(texture, rect) {}
	~static_entity();

	//public methods
	float getWidthAndHeight() const;
	void update(float &time);

private:
	const float widthAndHeight = 5.0;	//ß òóò ïîñòàâèë 10 òîëüêî ÷òîáû îíî ñîáèðàëîñü
};

