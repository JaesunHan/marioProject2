#pragma once
#include "gameNode.h"
enum ENEMYSTATUS
{
	ENEMYIDLE,
	ENEMYWALK

};
enum ENEMYDIRECTION
{
	ENEMYLEFT,
	ENEMYRIGHT
};

class enemy : public gameNode
{
protected:
	//중점 좌표
	float _x, _y;
	//적 이미지
	image* _img;
	animation* _anim;
	RECT _rc;
	float _angle, _spd;
	ENEMYSTATUS	_status;
	ENEMYDIRECTION _direction;


	int _width, _height;

public:
	virtual HRESULT init(string imgKey, char* imgFileName, float x, float y, int totalWidth, int totalHeight, int frameNumX, int frameNumY);
	virtual void update();
	virtual void release();
	virtual void render();
	virtual void draw(HDC hdc);

	virtual void startAnim();

	enemy();
	~enemy();
};

