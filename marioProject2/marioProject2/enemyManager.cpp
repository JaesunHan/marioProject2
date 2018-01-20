#include "stdafx.h"
#include "enemyManager.h"



enemyManager::enemy()
{

}

enemyManager::~enemy()
{

}

HRESULT enemyManager::init()
{
	_wiggle = new enemyWiggle;
	_wiggle->init();
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

