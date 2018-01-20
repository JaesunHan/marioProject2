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

	return S_OK;
}
void titleScene::release()
{

}
void titleScene::update() 
{

}
void titleScene::render() 
{
	IMAGEMANAGER->findImage("titleBackGround")->render(getMemDC(),0,0);
}