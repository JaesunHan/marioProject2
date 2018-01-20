#pragma once
#include "player.h"

class tanukiMario : public player
{
private:

public:
	HRESULT init();
	void release();
	void update();
	void render();

	tanukiMario();
	~tanukiMario();
};

