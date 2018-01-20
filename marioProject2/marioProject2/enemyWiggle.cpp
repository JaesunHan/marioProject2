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
	
	enemy::init("enemyWiggle", "./image/Wiggler.bmp", WINSIZEX/2, WINSIZEY-250, 720, 180, 4, 2);
	_angle = PI;
	_spd = 2.0f;
	
	_direction = ENEMYLEFT;
	_status = ENEMYIDLE;

	return S_OK;
}
void enemyWiggle::update()	   
{
	enemy::update();
	if (KEYMANAGER->isOnceKeyDown('S')) {
		enemy::startAnim();
		_status = ENEMYWALK;
	}

}
void enemyWiggle::release()	   
{

}

void enemyWiggle::draw(HDC hdc)
{
	
	_img->aniRender(hdc, _x, _y, _anim);
}
