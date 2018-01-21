#pragma once
#include "gameNode.h"
#include "enemyManager.h"
#include "tanukiMario.h"
class gameScene : public gameNode
{
private:
	player * _player;
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

