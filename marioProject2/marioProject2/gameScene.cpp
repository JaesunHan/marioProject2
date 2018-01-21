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
	IMAGEMANAGER->addImage("°ÔÀÓ¾À¹é±×¶ó¿îµå", ".\\image\\playSceneBackgroundFront.bmp", 8454, 1302, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("°ÔÀÓ¾À·¹ÀÌ¾Æ¿ô", ".\\image\\playSceneBackgroundBack.bmp", 8454, 1302, true, RGB(255, 0, 255));
	_EM = new enemyManager;
	_EM->init();
	_player = new tanukiMario;
	_player->init("tanukiMarioIdleImage", ".\\image\\tanukiMarioIdle.bmp", 100, 535, 126, 270, 1, 2, TANUKI);
<<<<<<< HEAD
	
	_basicMario = new basicMario;

=======
	_EM->setPlayer(_player);

<<<<<<< HEAD
	CAMERAMANAGER->getBackGroundMemory(IMAGEMANAGER->findImage("°ÔÀÓ¾À¹é±×¶ó¿îµå"));
=======
	//ÀÔÀå È¿°úÀ½
	SOUNDMANAGER->play("menuEnter");

	//BGM play
	SOUNDMANAGER->play("BGM", 0.5f);
>>>>>>> 18fb4a36626db6e49bbcff0e41ef32ad2a4bc4fb
>>>>>>> 9a828e3f89c7374d9c87f610bc2da65d21a0a4c2

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
	CAMERAMANAGER->render("°ÔÀÓ¾À·¹ÀÌ¾Æ¿ô", getMemDC(), 0, 0);
	CAMERAMANAGER->render("°ÔÀÓ¾À¹é±×¶ó¿îµå", getMemDC(), 0, 0);
	_EM->render();
	_player->render();
}

void gameScene::collision(void)
{
<<<<<<< HEAD

=======

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
			HDC hdc = IMAGEMANAGER->findImage("°ÔÀÓ¾À·¹ÀÌ¾Æ¿ô")->getMemDC();

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
			//for ³¡
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

		HDC hdc = IMAGEMANAGER->findImage("°ÔÀÓ¾À·¹ÀÌ¾Æ¿ô")->getMemDC();
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
>>>>>>> 90579ed3f8142dc46cdb345c1c61c6a9e4cb940a
}