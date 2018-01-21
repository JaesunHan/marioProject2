#include "stdafx.h"
#include "tanukiMario.h"

tanukiMario::tanukiMario()
{
}


tanukiMario::~tanukiMario()
{

}

HRESULT tanukiMario::init()
{
	return S_OK;
}

void tanukiMario::release()
{

}

void tanukiMario::update() 
{
	KeyControl();
}

void tanukiMario::render() 
{
	//IMAGEMANAGER->findImage("tanukiMarioIdleImage")->frameRender(getMemDC(), _playerX, _playerY, _currentFrameX, _directionNum);
	IMAGEMANAGER->frameRender("tanukiMarioIdleImage", getMemDC(), _playerX, _playerY, _currentFrameX, _directionNum);

}
