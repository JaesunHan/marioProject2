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
	_currentFrameX = _currentFrameY = 0;				//������ ����
	_count = 0;											//������ ������ ���� ī��Ʈ
	_typeNum = playerType; 								//�÷��̾� Ÿ�� ����

	_playerX = x;										//�÷��̾� x��ǥ
	_playerY = y;										//�÷��̾� y��ǥ
	_probeY = 0;										//�÷��̾� �ٴ� ���κ�

	_imageName = imgKey;
	IMAGEMANAGER->findImage(_imageName)->setCenter(_playerX, _playerY);
	CAMERAMANAGER->setCameraXY(_playerX, _playerY);
	


	//�÷��̾Ʈ
	_playerRc = RectMakeCenter(_playerX, _playerY, IMAGEMANAGER->findImage(_imageName)->getFrameWidth(), IMAGEMANAGER->findImage(_imageName)->getFrameHeight());

	_probeX = _playerRc.left;		// �÷��̾� ��Ʈ�� left�� ���� 
	_probeY = _playerRc.top;		// �÷��̾� ��Ʈ�� top���� ����

									/////////���¿� ���� �⺻����//////////

	_directionNum = RIGHT;					//������ ���� �����ϱ� Ⱦ��ũ�� ����
	_statusNum = IDLE;						//���������ڴ��
	_whereNum = ONLAND;						//������ ������....
	_speed = 3.0f;							//���ǵ�
	_countDead = 0;							//�׾����� ī��Ʈ
	_angle = PI;							//Ⱦ��ũ���̴ϱ�.. 180��
	_gravity = 0.14f;						//�߷°�
	_jumpPower = 3.0f;						//�����Ŀ�


								//////���� �Ұ�///////
	_isRight = true;			//������ ���� �ִ�?
	_isIdle = true;				//������
	_isJump = false;			//�������´�?	
	_isGravity = false;			//�߷��� �����ÿ��� true
	_isBasic = true;			//������ �����������Դϴ�.


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
	{//����
		_statusNum = MOVE;

		CAMERAMANAGER->plusCamX(_playerX, -_speed);
		//_playerX -= _speed;

	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{//������
		_statusNum = MOVE;
		CAMERAMANAGER->plusCamX(_playerX, +_speed);
		//_playerX += _speed;

	}
	if (KEYMANAGER->isStayKeyDown('W'))
	{//����
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
	{//�Ʒ�
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

	//�̹��� ��Ʈ�ѿ� ����ġ ���̽���
	//�� ���̽����� �̹����� �־��ָ� �˴ϴ�.
	//_imageName = IMAGEMANAGER->findImage("�̹�����") ������� �� ���̽����� �̹����� �ָ� �ɰ� �����ϴ�.

	switch (_statusNum)
	{
	default: //IDLE�����̹��� ����Ʈ�� 
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

