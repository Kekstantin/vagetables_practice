#pragma once
#include "entity.h"
class static_entity :
	public entity
{
public:
	//const&destr
	static_entity(const float widthAndHeight);
	~static_entity();

	//public methods
	float getWidthAndHeight() const;

private:
	const float widthAndHeight = 10.0;	//ß òóò ïîñòàâèë 10 òîëüêî ÷òîáû îíî ñîáèðàëîñü
};

