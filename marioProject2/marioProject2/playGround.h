#pragma once
#include "gameNode.h"
//#include "starcraftScene.h"
#include "selectScene.h"
#include "titleScene.h"
#include "gameScene.h"



class playGround : public gameNode
{
private:
	//selectScene* _select;

public:
	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual void release(void);		//�޸� ���� ����
	virtual void update(void);		//������Ʈ(����)
	virtual void render(void);		//�׷��ִ� �Լ�

	void addImage(void);
	void addSound(void);

	playGround();
	~playGround();
};

