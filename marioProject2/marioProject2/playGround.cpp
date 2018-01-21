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

	SCENEMANAGER->addScene("셀렉트씬", new selectScene);
	SCENEMANAGER->addScene("타이틀씬", new titleScene);
	SCENEMANAGER->addScene("게임씬", new gameScene);
	
	SCENEMANAGER->changeScene("타이틀씬");


	
	return S_OK;
}

//메모리 관련 삭제
void playGround::release(void)
{
	gameNode::release();

}

//연산
void playGround::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();

		
}

//그리는거.......
void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== 이 위는 손대지 마시오 =========================
	
	SCENEMANAGER->render();
	
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	TIMEMANAGER->render(getMemDC());

	//================== 이 아래는 손대지 마시오 ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc영역에 그려준다 
}
