#include "stdafx.h"
#include "basicMario.h"

basicMario::basicMario()
{
}


basicMario::~basicMario()
{
}

HRESULT basicMario::init()
{
	return S_OK;
}

void basicMario::release()
{
}

void basicMario::update()
{
	player::update();
}

void basicMario::render()
{
	player::render();
	//IMAGEMANAGER->findImage("베이직마리오대기_우")->frameRender(getMemDC(), _playerX, _playerY, _currentFrameX, _directionNum);
}

image* basicMario::imageControl()
{

	

	switch (_statusNum)
	{
	default:
		_imageName = "베이직마리오대기_우";
		return IMAGEMANAGER->findImage(_imageName);

		break;

	case IDLE:
		_imageName="베이직마리오대기_우";
		return IMAGEMANAGER->findImage(_imageName);

		break;

	case JUMP:
		_imageName ="베이직마리오점프_우";
		return IMAGEMANAGER->findImage(_imageName);

		break;

	case MOVE:
		_imageName = "베이직마리오무브_우";
		return IMAGEMANAGER->findImage(_imageName);

		break;

	case RUN://베이직마리오는 런 없습니당..........흐규흐규
		break;
	}
	return NULL;
}
