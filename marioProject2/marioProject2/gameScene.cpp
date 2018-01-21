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
	

	//입장 효과음
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
	IMAGEMANAGER->findImage("게임씬레이아웃")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("게임씬백그라운드")->render(getMemDC(), 0, 0);
	_EM->render();
	_player->render();
}

void gameScene::collision(void)
{

}