#include "stdafx.h"
#include "shovelMario.h"


shovelMario::shovelMario()
{
}
shovelMario::~shovelMario()
{
}



image* shovelMario::imageControl()
{

	//�̹��� ��Ʈ�ѿ� ����ġ ���̽���
	//�� ���̽����� �̹����� �־��ָ� �˴ϴ�.
	//_imageName = IMAGEMANAGER->findImage("�̹�����") ������� �� ���̽����� �̹����� �ָ� �ɰ� �����ϴ�.

	switch (_statusNum)
	{
		default: //IDLE�����̹��� ����Ʈ�� 
			if (_directionNum == RIGHT)
			{
				_imageName = "sKnightIdleR";
				return IMAGEMANAGER->findImage(_imageName);
			}
			else if (_directionNum == LEFT)
			{
				_imageName = "sKnightIdleL";
				return IMAGEMANAGER->findImage(_imageName);
			}	
		break;

		case IDLE:
			if (_directionNum == RIGHT)
			{
				_imageName = "sKnightIdleR";
				return IMAGEMANAGER->findImage(_imageName);
			}
			else if (_directionNum == LEFT)
			{
				_imageName = "sKnightIdleL";
				return IMAGEMANAGER->findImage(_imageName);
			}
		break;

		case JUMP:
			if (_directionNum == RIGHT)
			{
				_imageName = "sKnightJumpR";
				IMAGEMANAGER->findImage(_imageName);
			}
			else if (_directionNum == LEFT)
			{
				_imageName = "sKnightJumpL";
				IMAGEMANAGER->findImage(_imageName);
			}
		break;

		case MOVE:
			if (_directionNum == RIGHT)
			{
				_imageName = "sKnightWalkR";
				return IMAGEMANAGER->findImage(_imageName);
			}
			else if (_directionNum == LEFT)
			{
				_imageName = "sKnightWalkL";
				return IMAGEMANAGER->findImage(_imageName);
			}
		break;

		case ATTACK:
			if (_directionNum == RIGHT)
			{
				_imageName = "sKnightAttackR";
				return IMAGEMANAGER->findImage(_imageName);
			}
			else if (_directionNum == LEFT)
			{
				_imageName = "sKnightAttackL";
				return IMAGEMANAGER->findImage(_imageName);
			}
		break;

		case SKILL:
			if (_directionNum == RIGHT)
			{
				//_imageName = "sKnightWalkR";
				//return IMAGEMANAGER->findImage(_imageName);
			}
			else if (_directionNum == LEFT)
			{
				//_imageName = "sKnightWalkL";
				//return IMAGEMANAGER->findImage(_imageName);
			}
		break;

		case RUN:
			return NULL;
		break;
	} 
	return NULL;
}


void shovelMario::playerFrameControl()
{
	switch (_statusNum)
	{
		default: //IDLE�����̹��� ����Ʈ�� 
			if (_count % 5 == 0)
			{
				IMAGEMANAGER->findImage(_imageName)->setFrameX(_currentFrameX);
				_currentFrameX++;
				if (_currentFrameX >= IMAGEMANAGER->findImage(_imageName)->getMaxFrameX())
					_currentFrameX = 0;

				_count = 0;
			}
		break;

		case IDLE:
			if (_count % 5 == 0)
			{
				IMAGEMANAGER->findImage(_imageName)->setFrameX(_currentFrameX);
				_currentFrameX++;
				if (_currentFrameX >= IMAGEMANAGER->findImage(_imageName)->getMaxFrameX())
					_currentFrameX = 0;

				_count = 0;
			}
		break;

		case JUMP:
			if (_count % 5 == 0)
			{
				IMAGEMANAGER->findImage(_imageName)->setFrameX(_currentFrameX);
				_currentFrameX++;
				if (_currentFrameX >= IMAGEMANAGER->findImage(_imageName)->getMaxFrameX() - 1)
					_currentFrameX = 0;

				_count = 0;
			}
		break;

		case MOVE:
			if (_count % 5 == 0)
			{
				IMAGEMANAGER->findImage(_imageName)->setFrameX(_currentFrameX);
				_currentFrameX++;
				if (_currentFrameX >= IMAGEMANAGER->findImage(_imageName)->getMaxFrameX())
					_currentFrameX = 0;

				_count = 0;
			}
		break;

		case ATTACK:
			if (_count % 5 == 0)
			{
				IMAGEMANAGER->findImage(_imageName)->setFrameX(_currentFrameX);
				_currentFrameX++;
				if (_currentFrameX >= IMAGEMANAGER->findImage(_imageName)->getMaxFrameX())
					_currentFrameX = 0;

				_count = 0;
			}
		break;

		case SKILL:
			if (_count % 5 == 0)
			{
				IMAGEMANAGER->findImage(_imageName)->setFrameX(_currentFrameX);
				_currentFrameX++;
				if (_currentFrameX >= IMAGEMANAGER->findImage(_imageName)->getMaxFrameX())
					_currentFrameX = 0;

				_count = 0;
			}
		break;

		case RUN:
		
		break;
	}
}