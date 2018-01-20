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
	IMAGEMANAGER->addFrameImage("tanukiMarioIdleImage", ".\\image\\tanukiMarioIdle.bmp", 126, 270, 1, 2, true, RGB(255, 0, 255));
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

}
