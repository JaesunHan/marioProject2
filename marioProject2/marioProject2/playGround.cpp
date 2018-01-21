#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{

}

HRESULT playGround::init()
{
	gameNode::init(true);
	addImage();
	addSound();

	SCENEMANAGER->addScene("����Ʈ��", new selectScene);
	SCENEMANAGER->addScene("Ÿ��Ʋ��", new titleScene);
	SCENEMANAGER->addScene("���Ӿ�", new gameScene);
	
	SCENEMANAGER->changeScene("Ÿ��Ʋ��");


	
	return S_OK;
}

//�޸� ���� ����
void playGround::release(void)
{
	gameNode::release();

}

//����
void playGround::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();

		
}

//�׸��°�.......
void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== �� ���� �մ��� ���ÿ� =========================
	
	SCENEMANAGER->render();
	
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	TIMEMANAGER->render(getMemDC());

	//================== �� �Ʒ��� �մ��� ���ÿ� ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc������ �׷��ش� 
}
