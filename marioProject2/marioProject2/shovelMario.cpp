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

	//이미지 컨트롤용 스위치 케이스문
	//각 케이스별의 이미지를 넣어주면 됩니다.
	//_imageName = IMAGEMANAGER->findImage("이미지명") 사용으로 각 케이스별의 이미지를 주면 될거 같습니다.

	switch (_statusNum)
	{
		default: //IDLE상태이미지 디폴트로 
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