#pragma once
#include "gameNode.h"
#include "button.h"
#include "action.h"

//���� ĳ���� ����ü
struct tagPlayer
{
	image* img;               //���� �̹���
	RECT rc;                  //Ȱ��ȭ ��Ʈ
	int x, y;                 //��ġ��ǥX, Y
	animation* ani;           //Ȱ��ȭ ���ϸ��̼�
};

class selectScene : public gameNode
{
private:
	image* _selectBg;        //���þ� ��׶��� �̹���
	tagPlayer _Mario1;  //������1
	tagPlayer _Mario2;  //������1
	tagPlayer _Mario3;  //������1





public:
	HRESULT init();
	void release();
	void update();
	void render();

	//�������� �Ǿ��־ static���� �����(�ݹ��Լ��� ���� �Լ�)
	static void cbSceneChange();
	


	selectScene();
	~selectScene();
};

