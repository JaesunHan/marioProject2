#include "stdafx.h"
#include "shovelMario.h"


shovelMario::shovelMario()
{
}
shovelMario::~shovelMario()
{
}



void shovelMario::imageControl()
{

	//�̹��� ��Ʈ�ѿ� ����ġ ���̽���
	//�� ���̽����� �̹����� �־��ָ� �˴ϴ�.
	//_imageName = IMAGEMANAGER->findImage("�̹�����") ������� �� ���̽����� �̹����� �ָ� �ɰ� �����ϴ�.

	switch (_statusNum)
	{
		default: //IDLE�����̹��� ����Ʈ�� 
			if (_directionNum == RIGHT)
			{
				_imageName = IMAGEMANAGER->findImage("sKnightIdleR");
			}
			else if (_directionNum == LEFT)
			{
				_imageName = IMAGEMANAGER->findImage("sKnightIdleL");
			}	
		break;

		case IDLE:
			if (_directionNum == RIGHT)
			{
				_imageName = IMAGEMANAGER->findImage("sKnightIdleR");
			}
			else if (_directionNum == LEFT)
			{
				_imageName = IMAGEMANAGER->findImage("sKnightIdleL");
			}
		break;

		case JUMP:
			if (_directionNum == RIGHT)
			{
				_imageName = IMAGEMANAGER->findImage("sKnightJumpR");
			}
			else if (_directionNum == LEFT)
			{
				_imageName = IMAGEMANAGER->findImage("sKnightJumpL");
			}
		break;

		case MOVE:
			if (_directionNum == RIGHT)
			{
				_imageName = IMAGEMANAGER->findImage("sKnightWalkR");
			}
			else if (_directionNum == LEFT)
			{
				_imageName = IMAGEMANAGER->findImage("sKnightWalkL");
			}
		break;

		case RUN:

		break;
	}
}