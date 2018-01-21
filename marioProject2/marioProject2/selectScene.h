#pragma once
#include "gameNode.h"
#include "button.h"
#include "action.h"

//ĳ���� ���� ����ü
struct tagPlayer
{
	image* img;               //���� �̹���
	RECT rc;                  //Ȱ��ȭ ��Ʈ
	int x, y;                 //��ġ��ǥX, Y
	animation* ani;           //Ȱ��ȭ ���ϸ��̼�
};

//���õ� ĳ����
enum PLAYER_SELETCT
{
	SELECT_NONE,
	SELECT_MARIO1,
	SELECT_MARIO2,
	SELECT_MARIO3
};

class selectScene : public gameNode
{
private:
	image* _selectBg;   //���þ� ��׶��� �̹���
	tagPlayer _Mario1;  //������1
	tagPlayer _Mario2;  //������2
	tagPlayer _Mario3;  //������3

	int _selectPlayer;   //���õ� ĳ���� ����
	bool _selectSoundPlay;



public:
	HRESULT init();
	void release();
	void update();
	void render();

	
	//============================================================= ������
	inline int getSelectPlayer() { return _selectPlayer; }

	selectScene();
	~selectScene();
};

