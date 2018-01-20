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
	IMAGEMANAGER->addImage("°ÔÀÓ¾À¹é±×¶ó¿îµå", ".\\image\\playSceneBackgroundFront.bmp", 960, 720, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("°ÔÀÓ¾À·¹ÀÌ¾Æ¿ô", ".\\image\\playSceneBackgroundBack.bmp", 960, 720, true, RGB(255, 0, 255));
	_EM = new enemyManager;
	_EM->init();

	return S_OK;
}

void gameScene::release()
{

}

void gameScene::update() 
{
	_EM->update();
}

void gameScene::render() 
{
	IMAGEMANAGER->findImage("°ÔÀÓ¾À·¹ÀÌ¾Æ¿ô")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("°ÔÀÓ¾À¹é±×¶ó¿îµå")->render(getMemDC(), 0, 0);
	_EM->render();
}
