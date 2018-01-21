#include "stdafx.h"
#include "enemyWiggle.h"
#include "player.h"


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
	_spd = 1.6f;
	
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
	if (KEYMANAGER->isStayKeyDown('G'))
	{
		Rectangle(hdc, _icanseeyou.left, _icanseeyou.top, _icanseeyou.right, _icanseeyou.bottom);
	}
	_img->aniRender(hdc, _x, _y, _anim);
}
