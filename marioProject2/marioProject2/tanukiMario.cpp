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

}

void tanukiMario::render() 
{
	IMAGEMANAGER->findImage("tanukiMarioIdleImage")->frameRender(getMemDC(), _playerX, _playerY, _currentFrameX, _directionNum);
}
