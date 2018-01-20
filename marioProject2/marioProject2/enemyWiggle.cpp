#include "stdafx.h"
#include "enemyWiggle.h"



enemyWiggle::enemyWiggle()
{
}


enemyWiggle::~enemyWiggle()
{

}

HRESULT enemyWiggle::init()	   
{
	_x = WINSIZEX / 2;
	_y = WINSIZEY - 200;
	enemy::init("enemyWiggle", "./image/Wiggler.bmp", _x, _y, 720, 90, 4, 1);
	
	return S_OK;
}
void enemyWiggle::update()	   
{
	enemy::update();
	if (KEYMANAGER->isOnceKeyDown('S'))	enemy::startAnim();
}
void enemyWiggle::release()	   
{

}

void enemyWiggle::draw(HDC hdc)
{
	
	_img->aniRender(hdc, _x, _y, _anim);
}
