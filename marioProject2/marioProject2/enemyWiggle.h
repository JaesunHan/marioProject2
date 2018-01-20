#pragma once
#include "enemy.h"

class enemyWiggle : public enemy
{
private:
public:
	HRESULT init();
	void update();
	void release();
	//void render();
	void draw(HDC hdc);

	enemyWiggle();
	~enemyWiggle();
};

