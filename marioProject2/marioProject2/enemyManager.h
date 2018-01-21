#pragma once
#include "gameNode.h"
#include "enemyWiggle.h"

class player;
class enemyManager : public gameNode
{
private:
	enemyWiggle* _wiggle;
	player* _p;
public:
	HRESULT init();
	void update();
	void release();
	void render();
	void draw();

	void setPlayer(player* p)
	{
		_p = p;
	}

	enemyManager();
	~enemyManager();
};

