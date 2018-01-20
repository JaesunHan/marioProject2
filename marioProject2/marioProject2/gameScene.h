#pragma once
#include "gameNode.h"
#include "enemyManager.h"
#include "tanukiMario.h"
class gameScene : public gameNode
{
private:
	player * _player;
	enemyManager* _EM;
	
public:
	gameScene();
	~gameScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

