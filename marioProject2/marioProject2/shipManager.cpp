#include "stdafx.h"
#include "shipManager.h"


shipManager::shipManager()
{
}


shipManager::~shipManager()
{

}

HRESULT shipManager::init()
{
	_ship[SHIPKIND_BATTLE] = new battle;
	_ship[SHIPKIND_BATTLE]->init("battle", 0, 0);

	_ship[SHIPKIND_BATTLE2] = new battle2;
	_ship[SHIPKIND_BATTLE2]->init("battle2", 200, 200);

	_focusShip = _ship[SHIPKIND_BATTLE];

	_space = new space;
	_space->init();
	_space->setShip(_focusShip);


	return S_OK;
}

void shipManager::release()
{

}

void shipManager::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_focusShip = _ship[SHIPKIND_BATTLE];
		_space->setShip(_focusShip);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		_focusShip = _ship[SHIPKIND_BATTLE2];
		_space->setShip(_focusShip);
	}

	for (int i = 0; i < SHIPKIND_END; ++i)
	{
		_ship[i]->update();
	}

	//포커스 맞춰진 애만 키가 먹도록 한다
	_focusShip->keyControl();
}

void shipManager::render() 
{
	//배경 + 카메라 렌더
	_space->render();

	for (int i = 0; i < SHIPKIND_END; ++i)
	{
		//포커스 맞춰진 배면, 포커싱 맞춰진 걸로 렌더
		if (_focusShip == _ship[i])
		{
			_focusShip->focusDraw();
		}
		else //그 포커스 맞춰진 애로부터 상대적으로 렌더
		{
			_ship[i]->defaultDraw(_focusShip->getRect());
		}
	}
}
