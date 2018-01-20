#include "stdafx.h"
#include "enemy.h"



enemy::enemy()
{

}

enemy::~enemy()
{

}

HRESULT enemy::init(string imgKey, char* imgFileName, float x, float y, int totalWidth, int totalHeight, int frameNumX, int frameNumY)
{
	_img = IMAGEMANAGER->addFrameImage(imgKey, imgFileName, totalWidth, totalHeight, frameNumX, frameNumY, true, RGB(255, 0, 255));

	_anim = new animation;
	_anim->init(_img->getWidth(), _img->getHeight(), _img->getFrameWidth(), _img->getFrameHeight());
	_anim->setDefPlayFrame(false, true);
	_anim->setFPS(1);


	return S_OK;
}
void enemy::update() 
{
	if (_anim != NULL)
	{
		_anim->frameUpdate(TIMEMANAGER->getElapsedTime() * 8);
	}
}
void enemy::release()
{

}
void enemy::render() 
{
	draw(getMemDC());
}
void enemy::draw(HDC hdc)	 
{
	_img->aniRender(hdc, _x, _y, _anim);
}
void enemy::startAnim()
{
	_anim->start();
}