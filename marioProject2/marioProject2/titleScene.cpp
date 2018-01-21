#include "StdAfx.h"
#include "titleScene.h"


titleScene::titleScene(void)
{
}


titleScene::~titleScene(void)
{

}

HRESULT titleScene::init()
{
	IMAGEMANAGER->addImage("backGround(title)", ".//image//backGround(title).bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));


	return S_OK;
}
void titleScene::release()
{

}
void titleScene::update()
{
	if(KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SCENEMANAGER->changeScene("¼¿·ºÆ®¾À");
	}
}
void titleScene::render() 
{
	IMAGEMANAGER->findImage("backGround(title)")->render(getMemDC(),0,0);
}