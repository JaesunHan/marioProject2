#include "stdafx.h"
#include "player.h"


player::player()
{
}


player::~player()
{
}

HRESULT player::init()
{
	return S_OK;
}

HRESULT player::init(const char * imageName, float x, float y, PLAYERTYPE playerType)
{
	_currentFrameX = _currentFrameY = 0;				//프레임 관리
	_count = 0;											//프레임 돌리기 위한 카운트
	_typeNum = playerType; 								//플레이어 타입 받장

	_playerX = x;										//플레이어 x좌표
	_playerY = y;										//플레이어 y좌표
	_probeY = 0;										//플레이어 바닥 프로브

	_imageName = IMAGEMANAGER->findImage(imageName);
	_imageName->setCenter(x, y);


	//플레이어렉트
	_playerRc = RectMakeCenter(_playerX, _playerY, _imageName->getFrameWidth(), _imageName->getFrameHeight());


	//상태에 대한 기본세팅//

	_directionNum = RIGHT;					//오른쪽 보고 있으니까 횡스크롤 만세
	_statusNum = IDLE;						//대기대기대기대기박대기
	_whereNum = ONLAND;						//땅위에 있지용....
	_speed = 3.0f;							//스피드
	_countDead = 0;							//죽었는지 카운트
	_angle = PI;							//횡스크롤이니까.. 180도
	_gravity = 0.14f;						//중력값
	_jumpPower = 3.0f;						//점프파워


											//상태 불값
	_isRight = true;			//오른쪽 보고 있니?
	_isIdle = true;				//대기상태
	_isJump = false;			//점프상태니?	
	_isGravity = false;			//중력은 점프시에만 true
	_isBasic = true;			//베이직 마리오상태입니다.


	return S_OK;
}


void player::release()
{
}

void player::update()
{
	_count++;


	playerFrameControl();
	move();
}

void player::render()
{
	draw();
}

void player::playerFrameControl()
{
	if (_count % 5 == 0)
	{
		_imageName->setFrameX(_currentFrameX);
		_currentFrameX++;
		if (_currentFrameX >= _imageName->getMaxFrameX())
			_currentFrameX = 0;

		_count = 0;
	}
}

void player::move()
{

}

void player::KeyControl()
{
	if (KEYMANAGER->isStayKeyDown('A'))
	{//왼쪽

		_imageName->setX(_imageName->getX() - _speed);
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{//오른쪽
		_imageName->setX(_imageName->getX() + _speed);
	}
	if (KEYMANAGER->isStayKeyDown('W'))
	{//점프
		_isJump = true;
		_whereNum = OFFLAND;
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{//아래

	}
}

void player::playerJump()
{
}

void player::draw()
{
	_imageName->frameRender(getMemDC(), _playerRc.left, _playerRc.top, _currentFrameX, _currentFrameY);
}

void player::imageControl()
{
	switch (_statusNum)
	{
	default:
		break;
	}
}
