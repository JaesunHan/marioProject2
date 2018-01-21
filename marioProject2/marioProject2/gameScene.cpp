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
	IMAGEMANAGER->addImage("게임씬백그라운드", ".\\image\\playSceneBackgroundFront.bmp", 960, 720, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("게임씬레이아웃", ".\\image\\playSceneBackgroundBack.bmp", 960, 720, true, RGB(255, 0, 255));
	_EM = new enemyManager;
	_EM->init();
	_player = new tanukiMario;
	_player->init("tanukiMarioIdleImage", ".\\image\\tanukiMarioIdle.bmp", 100, 535, 126, 270, 1, 2, TANUKI);
<<<<<<< HEAD
	
	_basicMario = new basicMario;

=======
	_EM->setPlayer(_player);

	//입장 효과음
	SOUNDMANAGER->play("menuEnter");

	//BGM play
	SOUNDMANAGER->play("BGM", 0.5f);
>>>>>>> 18fb4a36626db6e49bbcff0e41ef32ad2a4bc4fb

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
	IMAGEMANAGER->findImage("게임씬레이아웃")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("게임씬백그라운드")->render(getMemDC(), 0, 0);
	_EM->render();
	_player->render();
}

void gameScene::collision(void)
{
	if (_player->getJumpPower() < 0)
	{

	}
	for (int i = 0; i < (_player->getJumpPower() * (-1) + 1); ++i)
	{

	}
}