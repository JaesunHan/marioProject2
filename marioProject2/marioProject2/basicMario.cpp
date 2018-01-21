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
	KeyControl();
}

void basicMario::render()
{
	IMAGEMANAGER->findImage("���������������_��")->frameRender(getMemDC(), _playerX, _playerY, _currentFrameX, _directionNum);
}

void basicMario::imageControl()
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

		_imageName = IMAGEMANAGER->findImage("���������������_��");
		if (_count % 5 == 0)
		{
			_imageName->setFrameX(_currentFrameX);
			_currentFrameX++;
			if (_currentFrameX >= _imageName->getMaxFrameX())
				_currentFrameX = 0;

			_count = 0;
		}
		break;

	case IDLE:
		_imageName = IMAGEMANAGER->findImage("���������������_��");
		if (_count % 5 == 0)
		{
			_imageName->setFrameX(_currentFrameX);
			_currentFrameX++;
			if (_currentFrameX >= _imageName->getMaxFrameX())
				_currentFrameX = 0;

			_count = 0;
		}
		break;

	case JUMP:
		_imageName = IMAGEMANAGER->findImage("����������������_��");
		if (_count % 5 == 0)
		{
			_imageName->setFrameX(_currentFrameX);
			_currentFrameX++;
			if (_currentFrameX >= _imageName->getMaxFrameX())
				_currentFrameX = 0;

			_count = 0;
		}
		break;

	case MOVE:
		_imageName = IMAGEMANAGER->findImage("����������������_��");
		if (_count % 5 == 0)
		{
			_imageName->setFrameX(_currentFrameX);
			_currentFrameX++;
			if (_currentFrameX >= _imageName->getMaxFrameX())
				_currentFrameX = 0;

			_count = 0;
		}
		break;

	case RUN://�������������� �� �����ϴ�..........������
		break;
	}
}
