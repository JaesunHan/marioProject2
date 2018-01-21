#include "stdafx.h"
#include "gameScene.h"



gameScene::gameScene()
{
}


gameScene::~gameScene()
{

}

HRESULT gameScene::init()
{
	IMAGEMANAGER->addImage("���Ӿ���׶���", ".\\image\\playSceneBackgroundFront.bmp", 8454, 1302, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���Ӿ����̾ƿ�", ".\\image\\playSceneBackgroundBack.bmp", 8454, 1302, true, RGB(255, 0, 255));
	CAMERAMANAGER->getBackGroundMemory(IMAGEMANAGER->findImage("���Ӿ���׶���"));
	_EM = new enemyManager;
	_EM->init();
	_player = new tanukiMario;
	_player->init("tanukiMarioIdle", ".\\image\\tanukiMarioIdle.bmp", 285, 1190, 126, 270, 1, 2, TANUKI);

	_EM->setPlayer(_player);
	
	_basicMario = new basicMario;




	

	//���� ȿ����
	SOUNDMANAGER->play("menuEnter");

	//BGM play
	SOUNDMANAGER->play("BGM", 0.5f);


	return S_OK;
}

void gameScene::release()
{

}

void gameScene::update() 
{
	_EM->update();
	_player->update();
	collision();
}

void gameScene::render() 
{
	CAMERAMANAGER->render("���Ӿ����̾ƿ�", getMemDC(), 0, 0);
	CAMERAMANAGER->render("���Ӿ���׶���", getMemDC(), 0, 0);
	_EM->render();
	_player->render();
}

void gameScene::collision(void)
{
	HDC hdc = IMAGEMANAGER->findImage("���Ӿ����̾ƿ�")->getMemDC();
	COLORREF color1;
	COLORREF color2;
	COLORREF color3;
	// �÷��̾ ������ �Ʒ��� ������ ��
	if (_player->getJumpPower() <= 0)
	{
		for (int i = 0; i < _player->getJumpPower() * (-1) + 1; i += 5)
		{
			color1 = GetPixel(hdc, _player->getRect().right, _player->getRect().bottom + i);
			if (!isMazen(color1))
			{
				_player->setJumpPower(0);
				_player->setPlayerY(_player->getRect().bottom + i);
				_player->setWhereNum(ONLAND);
				_player->setStatusNum(IDLE);
				break;
			}
			color1 = GetPixel(hdc, _player->getRect().left, _player->getRect().bottom + i);
			if (!isMazen(color1))
			{
				_player->setJumpPower(0);
				_player->setPlayerY(_player->getRect().bottom + i);
				_player->setWhereNum(ONLAND);
				_player->setStatusNum(IDLE);
				break;
			}
			color1 = GetPixel(hdc, (_player->getRect().right + _player->getRect().left) / 2, _player->getRect().bottom + i);
			if (!isMazen(color1))
			{
				_player->setJumpPower(0);
				_player->setPlayerY(_player->getRect().bottom + i);
				_player->setWhereNum(ONLAND);
				_player->setStatusNum(IDLE);
				break;
			}
		}
	}
	// �÷��̾ �Ʒ����� ���� �ö� ��
	if (_player->getJumpPower() > 0)
	{
		for (int i = 20; i > 0; --i)
		{
			color1 = GetPixel(hdc, _player->getRect().right, _player->getRect().top + i);
			if (!isMazen(color1))
			{
				_player->setJumpPower(0);
				_player->setPlayerY(_player->getRect().bottom + i + 1);
				break;
			}
			color1 = GetPixel(hdc, _player->getRect().left, _player->getRect().top + i);
			if (!isMazen(color1))
			{
				_player->setJumpPower(0);
				_player->setPlayerY(_player->getRect().bottom + i + 1);
				break;
			}
			color1 = GetPixel(hdc, (_player->getRect().right + _player->getRect().left) / 2, _player->getRect().top + i);
			if (!isMazen(color1))
			{
				_player->setJumpPower(0);
				_player->setPlayerY(_player->getRect().bottom + i + 1);
				break;
			}

		}
	}
	// �÷��̾� �ٴ��� ���� ��������
	if (_player->getPlayerWhere() == ONLAND)
	{
		color1 = GetPixel(hdc, _player->getRect().right, _player->getRect().bottom + 1);
		color2 = GetPixel(hdc, _player->getRect().left, _player->getRect().bottom + 1);
		color3 = GetPixel(hdc, (_player->getRect().right + _player->getRect().left) / 2, _player->getRect().bottom + 1);
		if (isMazen(color1) && isMazen(color2) && isMazen(color3))
		{
			_player->setWhereNum(OFFLAND);
		}
	}
	// �÷��̾ �¿� ���� �ε��� ��
	color1 = GetPixel(hdc, _player->getRect().right + 1, _player->getRect().bottom);
	color2 = GetPixel(hdc, _player->getRect().right + 1, _player->getRect().top);
	color3 = GetPixel(hdc, _player->getRect().right + 1, (_player->getRect().top + _player->getRect().bottom) / 2);
	if (!isMazen(color1) || !isMazen(color2) || !isMazen(color3))
	{
		_player->setPlayerRtBlock(true);
	}
	color1 = GetPixel(hdc, _player->getRect().left - 1, _player->getRect().bottom);
	color2 = GetPixel(hdc, _player->getRect().left - 1, _player->getRect().top);
	color3 = GetPixel(hdc, _player->getRect().left - 1, (_player->getRect().top + _player->getRect().bottom) / 2);
	if (!isMazen(color1) || !isMazen(color2) || !isMazen(color3))
	{
		_player->setPlayerLtBlock(true);
	}
}

bool gameScene::isMazen(COLORREF color)
{
	int r = GetRValue(color);
	int g = GetGValue(color);
	int b = GetBValue(color);

	return (r == 255 && g == 0 && b == 255);

}