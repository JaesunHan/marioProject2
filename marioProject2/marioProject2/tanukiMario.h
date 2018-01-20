#pragma once
#include "player.h"
class tanukiMario : public player
{
private:

public:
	tanukiMario();
	~tanukiMario();

	HRESULT init();
	void release();
	void update();
	void render();
};

