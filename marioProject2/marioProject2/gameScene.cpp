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
	_EM = new enemyManager;
	_EM->init();
	_player = new tanukiMario;
	_player->init("tanukiMarioIdle", ".\\image\\tanukiMarioIdle.bmp", 100, 535, 126, 270, 1, 2, TANUKI);

	
	_basicMario = new basicMario;


	_EM->setPlayer(_player);


	CAMERAMANAGER->getBackGroundMemory(IMAGEMANAGER->findImage("���Ӿ���׶���"));

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


	if (_isAir)
	{
		_gravity = 0.15f;
		_speed += _gravity;
		CAMERAMANAGER->plusCamY(_y, _speed);

		bool catchPt = false;
		float probeX = _x - _img->getFrameWidth() / 2;
		float probeY = _y + _img->getFrameHeight() / 2;
		{
			int saveX;
			HDC hdc = IMAGEMANAGER->findImage("���Ӿ����̾ƿ�")->getMemDC();

			for (; probeX < _x + _img->getFrameWidth() / 2; ++probeX)
			{
				COLORREF color = GetPixel(hdc, probeX, probeY);

				if (!isMazen(color))
				{
					bool once = true;

					while (!isMazen(color))
					{
						--probeY;
						color = GetPixel(hdc, probeX, probeY);
						if (once)
						{
							saveX = probeX;
							once = false;
						}
						if (isMazen(color))
						{
							int a = 0;
						}
					}
					catchPt = true;
				}
			}
			//for ��
			if (catchPt)
			{
				CAMERAMANAGER->plusCamY(_y, probeY - _y - _img->getFrameHeight() / 2);
				_isAir = false;
			}

		}
	}
	else if (!_isAir)
	{
		_gravity = 0.f;
		_speed = 0;

		float probeX = _x - _img->getFrameWidth() / 2;
		float probeY = _y + _img->getFrameHeight() / 2 + 1;

		HDC hdc = IMAGEMANAGER->findImage("���Ӿ����̾ƿ�")->getMemDC();
		{
			int bitt = 0;
			for (; probeX < _x + _img->getFrameWidth() / 2; ++probeX)
			{
				COLORREF color = GetPixel(hdc, probeX, probeY);

				if (!isMazen(color))
				{
					++bitt;
				}

				if (bitt)
				{
					_isAir = false;
				}
				else
				{
					_isAir = true;
				}
			}
		}

	}
}

bool gameScene::isMazen(COLORREF color)
{
	int r = GetRValue(color);
	int g = GetGValue(color);
	int b = GetBValue(color);

	return (r == 255 && g == 0 && b == 255);

}