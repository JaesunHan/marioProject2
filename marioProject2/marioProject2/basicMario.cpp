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

	//�̹��� ��Ʈ�ѿ� ����ġ ���̽���
	//�� ���̽����� �̹����� �־��ָ� �˴ϴ�.
	//_imageName = IMAGEMANAGER->findImage("�̹�����") ������� �� ���̽����� �̹����� �ָ� �ɰ� �����ϴ�.

	switch (_statusNum)
	{
	default: //IDLE�����̹��� ����Ʈ�� 
			 //IMAGEMANAGER->addFrameImage("���������������_��", "./image/mario_basic_idle_right.bmp", 70, 135, 1, 1, true, RGB(255, 0, 255));
			 //IMAGEMANAGER->addFrameImage("���������������_��", "./image/mario_basic_idle_left.bmp", 70, 135, 1, 1, true, RGB(255, 0, 255));
			 //IMAGEMANAGER->addFrameImage("����������������_��", "./image/mario_basic_move_left.bmp", 160, 135, 2, 1, true, RGB(255, 0, 255));
			 //IMAGEMANAGER->addFrameImage("����������������_��", "./image/mario_basic_move_right.bmp", 160, 135, 2, 1, true, RGB(255, 0, 255));
			 //IMAGEMANAGER->addFrameImage("����������������_��", "./image/mario_basic_jump_left.bmp", 83, 135, 1, 1, true, RGB(255, 0, 255));
			 //IMAGEMANAGER->addFrameImage("����������������_��", "./image/mario_basic_jump_right.bmp", 83, 135, 1, 1, true, RGB(255, 0, 255));

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
