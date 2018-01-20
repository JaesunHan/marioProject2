#include "stdafx.h"
#include "enemyManager.h"



enemyManager::enemyManager()
{

}

enemyManager::~enemyManager()
{

}

HRESULT enemyManager::init()
{
	_wiggle = new enemyWiggle;
	_wiggle->init();
	return S_OK;
}

void enemyManager::update()
{
	_wiggle->update();
}

void enemyManager::release()
{

}

void enemyManager::render()
{
	draw();
}

void enemyManager::draw()
{
	_wiggle->draw(getMemDC());
}

