#pragma once
#include "static_entity.h"
class dynamic_entity :
	public entity
{
public:
	//const&destr
	dynamic_entity();
	~dynamic_entity();

	//getters&setters
	void setSpeedX(speed_ speedX);
	void setSpeedY(speed_ speedY);
	void setWidthAndHeight(float widthAndHeight);
	speed_ getSpeedX() const;
	speed_ getSpeedY() const;
	float getWidthAndHeight() const;

	//public methods
	virtual void move() = 0;		//Метод, задающий движение динамической сущности
	virtual void update() = 0;		//метод, обновляющий расположение объекта на поле (НАРУШАЕТ МОДЕЛЬ MVC, Кость, лучше сунь это в обертку)
	virtual void eat();				//Метод, вызываемый при возникновении коллизии, увеличивает размер съедающей сущности
	
private:
	float widthAndHeight;
	speed_ speedX;
	speed_ speedY;
	//Тут еще цвет будет? Кость, лучше сунь это в обертку
};

