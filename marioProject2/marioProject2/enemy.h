#pragma once
#include "gameNode.h"
class enemy : public gameNode
{
private:
	//���� ��ǥ
	float _x, _y;
	//�� �̹���
	image* _img;
	animation* _anim;
	RECT _rc;

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

