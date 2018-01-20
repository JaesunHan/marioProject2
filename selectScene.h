#pragma once
#include "gameNode.h"
#include "button.h"
#include "action.h"

class selectScene : public gameNode
{
private:
	//�� �ٲܶ� ����� ��ư
	button* _btnSceneChange;
	button* _btnAngleUp;
	button* _btnAngleDown;

	action* _action;
	image* _actionImage;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	//�������� �Ǿ��־ static���� �����(�ݹ��Լ��� ���� �Լ�)
	static void cbSceneChange();
	
	static void cbAngleUp();
	static void cbAngleDown();


	selectScene();
	~selectScene();
};

