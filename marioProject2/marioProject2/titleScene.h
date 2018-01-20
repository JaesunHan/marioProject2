#pragma once
#include "gameNode.h"

class titleScene : public gameNode
{
private : 
	image* _image[3];
	
	int _x[3];
	int _y[3];


	int _selectX;
	int _selectY;

public:

	HRESULT init();
	void release();
	void update();
	void render();

	titleScene(void);
	~titleScene(void);
};

