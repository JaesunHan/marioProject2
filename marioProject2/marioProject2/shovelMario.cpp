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

	//이미지 컨트롤용 스위치 케이스문
	//각 케이스별의 이미지를 넣어주면 됩니다.
	//_imageName = IMAGEMANAGER->findImage("이미지명") 사용으로 각 케이스별의 이미지를 주면 될거 같습니다.

	switch (_statusNum)
	{
		default: //IDLE상태이미지 디폴트로 
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
		default: //IDLE상태이미지 디폴트로 
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