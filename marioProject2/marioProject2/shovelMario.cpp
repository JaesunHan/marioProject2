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

		case RUN:
			return NULL;
		break;
	} 
	return NULL;
}