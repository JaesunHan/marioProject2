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



HRESULT player::init(string imgKey, char* imgFileName, float x, float y, int totalWidth, int totalHeight, int frameNumX, int frameNumY, PLAYERTYPE playerType)
{
	_currentFrameX = _currentFrameY = 0;				//프레임 관리
	_count = 0;											//프레임 돌리기 위한 카운트
	_typeNum = playerType; 								//플레이어 타입 받장

	_playerX = x;										//플레이어 x좌표
	_playerY = y;										//플레이어 y좌표
	_probeY = 0;										//플레이어 바닥 프로브

	_imageName = imgKey;
	IMAGEMANAGER->findImage(_imageName)->setCenter(_playerX, _playerY);
	CAMERAMANAGER->setCameraXY(_playerX, _playerY);
	


	//플레이어렉트
	_playerRc = RectMakeCenter(_playerX, _playerY, IMAGEMANAGER->findImage(_imageName)->getFrameWidth(), IMAGEMANAGER->findImage(_imageName)->getFrameHeight());

	_probeX = _playerRc.left;		// 플레이어 렉트의 left로 검출 
	_probeY = _playerRc.top;		// 플레이어 렉트의 top으로 검출

									/////////상태에 대한 기본세팅//////////

	_directionNum = RIGHT;					//오른쪽 보고 있으니까 횡스크롤 만세
	_statusNum = IDLE;						//대기대기대기대기박대기
	_whereNum = ONLAND;						//땅위에 있지용....
	_speed = 3.0f;							//스피드
	_countDead = 0;							//죽었는지 카운트
	_angle = PI;							//횡스크롤이니까.. 180도
	_gravity = 0.14f;						//중력값
	_jumpPower = 3.0f;						//점프파워


								//////상태 불값///////
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
	KeyControl();
	//move();

	_playerRc = RectMake(_playerX - 35, _playerY - 135, 70, 135);
}

void player::render()
{
	draw();
}

void player::playerFrameControl()
{
	if (_count % 5 == 0)
	{
		IMAGEMANAGER->findImage(_imageName)->setFrameX(_currentFrameX);
		_currentFrameX++;
		if (_currentFrameX >= IMAGEMANAGER->findImage(_imageName)->getMaxFrameX())
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
		_statusNum = MOVE;

		CAMERAMANAGER->plusCamX(_playerX, -_speed);
		//_playerX -= _speed;

	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{//오른쪽
		_statusNum = MOVE;
		CAMERAMANAGER->plusCamX(_playerX, +_speed);
		//_playerX += _speed;

	}
	if (KEYMANAGER->isStayKeyDown('W'))
	{//점프
	 //_statusNum = JUMP;
	 //if (_whereNum == ONLAND)
	 //{
	 //	_whereNum = OFFLAND;
	 //	_isJump = true;
	 //}
		CAMERAMANAGER->plusCamY(_playerY, -_speed);
		_playerY -= _speed;
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{//아래
		CAMERAMANAGER->plusCamY(_playerY, +_speed);
		//_playerY += _speed;

	}

}

void player::playerJump()
{
	//if (_isJump)
	//{
	//	_imageName->setY(_imageName->getY() + _gravity);
	//	_playerRc = RectMakeCenter();
	//}
}

void player::draw()
{
	CAMERAMANAGER->frameRender(_imageName, getMemDC(), _playerRc.left, _playerRc.top, _currentFrameX, _currentFrameY);
}

void player::imageControl()
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

