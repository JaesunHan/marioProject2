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
}

void basicMario::render()
{
	IMAGEMANAGER->findImage("tanukiMarioIdleImage")->frameRender(getMemDC(), _playerX, _playerY, _currentFrameX, _directionNum);
}

void basicMario::imageControl()
{

	//�̹��� ��Ʈ�ѿ� ����ġ ���̽���
	//�� ���̽����� �̹����� �־��ָ� �˴ϴ�.
	//_imageName = IMAGEMANAGER->findImage("�̹�����") ������� �� ���̽����� �̹����� �ָ� �ɰ� �����ϴ�.

	switch (_statusNum)
	{
	default: //IDLE�����̹��� ����Ʈ�� 
		break;

	case IDLE:
		break;

	case JUMP:
		break;

	case MOVE:
		break;

	case RUN:
		break;
	}
}
