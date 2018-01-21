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
	player::update();
}

void tanukiMario::render() 
{
	player::render();
	//IMAGEMANAGER->findImage("tanukiMarioIdleImage")->frameRender(getMemDC(), _playerX, _playerY, _currentFrameX, _directionNum);
	//CAME->frameRender("tanukiMarioIdle", getMemDC(), _playerX, _playerY, _currentFrameX, _directionNum);

}
