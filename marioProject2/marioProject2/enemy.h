#pragma once
#include "gameNode.h"
class enemy : public gameNode
{
private:
	//���� ��ǥ
	float _x, _y;
	//�� �̹���
	image * _img;
	animation * _anim;
	RECT _rc;

	int _width, _height;



public:
	enemy();
	~enemy();
};

