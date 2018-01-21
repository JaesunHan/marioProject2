#pragma once
#include "player.h"


class shovelMario : public player
{
private:


public:
	image* imageControl();
	void playerFrameControl();

	shovelMario();
	~shovelMario();
};

