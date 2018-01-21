#pragma once
#include "gameNode.h"
#include "enemyManager.h"
#include "shovelMario.h"
#include "tanukiMario.h"
#include "basicMario.h"

class gameScene : public gameNode
{
private:
	player* _player;
	player* _basicMario;
	enemyManager* _EM;
	image* _backGround;


	//=================== ÇÈ¼¿collision ¹Ù´Ú===================
	image* _img;		//ÇÃ·¹ÀÌ¾î
	bool _isAir;
	float _gravity;
	float _speed;
	float _x;
	float _y;
	//===========================================
	
public:
	gameScene();
	~gameScene();

	void collision(void);

	HRESULT init();
	void release();
	void update();
	void render();

	bool isMazen(COLORREF color);
};

