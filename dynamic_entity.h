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
	virtual void move() = 0;		//�����, �������� �������� ������������ ��������
	virtual void update() = 0;		//�����, ����������� ������������ ������� �� ���� (�������� ������ MVC, �����, ����� ���� ��� � �������)
	virtual void eat();				//�����, ���������� ��� ������������� ��������, ����������� ������ ��������� ��������
	
private:
	float widthAndHeight;
	speed_ speedX;
	speed_ speedY;
	//��� ��� ���� �����? �����, ����� ���� ��� � �������
};

