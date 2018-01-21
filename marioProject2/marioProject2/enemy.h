#pragma once
#include "gameNode.h"

#define MAXPROBE 8
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

class player;
class enemy : public gameNode
{
protected:
	//레프트 탑 좌표
	float _x, _y;
	//적 이미지
	image* _img;
	animation* _anim;
	RECT _rc;
	float _angle, _spd;
	ENEMYSTATUS	_status;
	ENEMYDIRECTION _direction;
	RECT _icanseeyou;

	string _imgKeyString;
	int _width, _height;

	POINT _probe[MAXPROBE];
	RECT _moveArea;

public:
	virtual HRESULT init(string imgKey, char* imgFileName, float x, float y, int totalWidth, int totalHeight, int frameNumX, int frameNumY);
	virtual void update();
	virtual void release();
	virtual void render();
	virtual void draw(HDC hdc);

	virtual void startAnim();
	virtual float followPlayer(player* p);
	virtual void pixelCollisionFloor();

	enemy();
	~enemy();
};

