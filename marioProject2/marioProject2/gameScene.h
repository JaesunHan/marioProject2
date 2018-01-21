#pragma once
#include "gameNode.h"
#include "enemyManager.h"
#include "tanukiMario.h"
#include "basicMario.h"

class gameScene : public gameNode
{
private:
	player* _player;
	player* _basicMario;
	enemyManager* _EM;
	
public:
	gameScene();
	~gameScene();

	void collision(void);

	HRESULT init();
	void release();
	void update();
	void render();
};

