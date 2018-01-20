#pragma once
#include "gameNode.h"
#include "enemyWiggle.h"

class enemyManager : public gameNode
{
private:
	enemyWiggle* _wiggle;
public:
	HRESULT init();
	void update();
	void release();
	void render();
	void draw();



	enemy();
	~enemy();
};

