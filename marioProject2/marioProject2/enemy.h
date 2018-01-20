#pragma once
#include "gameNode.h"
class enemy : public gameNode
{
private:
	//중점 좌표
	float _x, _y;
	//적 이미지
	image * _img;
	animation * _anim;
	RECT _rc;

	int _width, _height;



public:
	enemy();
	~enemy();
};

