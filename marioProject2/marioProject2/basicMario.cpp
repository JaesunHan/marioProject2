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
	//IMAGEMANAGER->findImage("베이직마리오대기_우")->frameRender(getMemDC(), _playerX, _playerY, _currentFrameX, _directionNum);
}

image* basicMario::imageControl()
{

	//이미지 컨트롤용 스위치 케이스문
	//각 케이스별의 이미지를 넣어주면 됩니다.
	//_imageName = IMAGEMANAGER->findImage("이미지명") 사용으로 각 케이스별의 이미지를 주면 될거 같습니다.

	switch (_statusNum)
	{
	default: //IDLE상태이미지 디폴트로 
			 //IMAGEMANAGER->addFrameImage("베이직마리오대기_우", "./image/mario_basic_idle_right.bmp", 70, 135, 1, 1, true, RGB(255, 0, 255));
			 //IMAGEMANAGER->addFrameImage("베이직마리오대기_좌", "./image/mario_basic_idle_left.bmp", 70, 135, 1, 1, true, RGB(255, 0, 255));
			 //IMAGEMANAGER->addFrameImage("베이직마리오무브_좌", "./image/mario_basic_move_left.bmp", 160, 135, 2, 1, true, RGB(255, 0, 255));
			 //IMAGEMANAGER->addFrameImage("베이직마리오무브_우", "./image/mario_basic_move_right.bmp", 160, 135, 2, 1, true, RGB(255, 0, 255));
			 //IMAGEMANAGER->addFrameImage("베이직마리오점프_좌", "./image/mario_basic_jump_left.bmp", 83, 135, 1, 1, true, RGB(255, 0, 255));
			 //IMAGEMANAGER->addFrameImage("베이직마리오점프_우", "./image/mario_basic_jump_right.bmp", 83, 135, 1, 1, true, RGB(255, 0, 255));

		_imageName = "베이직마리오대기_우";
		return IMAGEMANAGER->findImage(_imageName);

		break;

	case IDLE:
		_imageName="베이직마리오대기_우";
		return IMAGEMANAGER->findImage(_imageName);

		break;

	case JUMP:
		_imageName ="베이직마리오점프_우";
		return IMAGEMANAGER->findImage(_imageName);

		break;

	case MOVE:
		_imageName = "베이직마리오무브_우";
		return IMAGEMANAGER->findImage(_imageName);

		break;

	case RUN://베이직마리오는 런 없습니당..........흐규흐규
		break;
	}
	return NULL;
}
