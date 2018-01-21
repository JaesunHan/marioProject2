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

	//이미지 컨트롤용 스위치 케이스문
	//각 케이스별의 이미지를 넣어주면 됩니다.
	//_imageName = IMAGEMANAGER->findImage("이미지명") 사용으로 각 케이스별의 이미지를 주면 될거 같습니다.

	switch (_statusNum)
	{
	default: //IDLE상태이미지 디폴트로 
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
