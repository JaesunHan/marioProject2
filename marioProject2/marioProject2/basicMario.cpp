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
	//IMAGEMANAGER->findImage("���������������_��")->frameRender(getMemDC(), _playerX, _playerY, _currentFrameX, _directionNum);
}

image* basicMario::imageControl()
{

	

	switch (_statusNum)
	{
	default:
		_imageName = "���������������_��";
		return IMAGEMANAGER->findImage(_imageName);

		break;

	case IDLE:
		_imageName="���������������_��";
		return IMAGEMANAGER->findImage(_imageName);

		break;

	case JUMP:
		_imageName ="����������������_��";
		return IMAGEMANAGER->findImage(_imageName);

		break;

	case MOVE:
		_imageName = "����������������_��";
		return IMAGEMANAGER->findImage(_imageName);

		break;

	case RUN://�������������� �� �����ϴ�..........������
		break;
	}
	return NULL;
}
