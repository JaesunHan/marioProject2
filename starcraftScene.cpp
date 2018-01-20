#include "stdafx.h"
#include "starcraftScene.h"

starcraftScene::starcraftScene()
{
}


starcraftScene::~starcraftScene()
{

}

HRESULT starcraftScene::init()
{
	_ship = new shipManager;
	_ship->init();


	return S_OK;
}

void starcraftScene::release()
{

}

void starcraftScene::update() 
{
	_ship->update();

	
}

void starcraftScene::render() 
{
	_ship->render();

}
