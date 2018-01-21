#pragma once
#include "player.h"
class basicMario :
	public player
{
public:
	basicMario();
	~basicMario();

	HRESULT init();
	void release();
	void update();
	void render();
	void imageControl();
};

