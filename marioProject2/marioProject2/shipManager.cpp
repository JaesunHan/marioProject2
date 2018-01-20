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

	//��Ŀ�� ������ �ָ� Ű�� �Ե��� �Ѵ�
	_focusShip->keyControl();
}

void shipManager::render() 
{
	//��� + ī�޶� ����
	_space->render();

	for (int i = 0; i < SHIPKIND_END; ++i)
	{
		//��Ŀ�� ������ ���, ��Ŀ�� ������ �ɷ� ����
		if (_focusShip == _ship[i])
		{
			_focusShip->focusDraw();
		}
		else //�� ��Ŀ�� ������ �ַκ��� ��������� ����
		{
			_ship[i]->defaultDraw(_focusShip->getRect());
		}
	}
}
