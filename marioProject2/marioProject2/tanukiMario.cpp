#include "stdafx.h"
#include "tanukiMario.h"

tanukiMario::tanukiMario()
{
}


tanukiMario::~tanukiMario()
{

}

HRESULT tanukiMario::init()
{
	return S_OK;
}

void tanukiMario::release()
{

}

void tanukiMario::update() 
{
	player::update();
}

void tanukiMario::render() 
{
	_count++;
	if (_count > 5)
	{
		_currentFrameX++;
		if (_currentFrameX >= 10) _currentFrameX = 0;
		_count = 0;
	}
	switch (_statusNum)
	{
	case IDLE:
		CAMERAMANAGER->frameRender("tanukiMarioIdle", getMemDC(), _playerRc.left - 28, _playerRc.top, 0, _directionNum);
		break;
	case JUMP:
		CAMERAMANAGER->frameRender("tanukiMarioJump", getMemDC(), _playerRc.left - 32, _playerRc.top, 0, _directionNum);
		break;
	case MOVE:
		CAMERAMANAGER->frameRender("tanukiMarioRunning", getMemDC(), _playerRc.left - 30, _playerRc.top, _currentFrameX % 2, _directionNum);
		break;
	case RUN:
		break;
	case ENDSTATUS:
		break;
	default:
		break;
	}

}
