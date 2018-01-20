#include "stdafx.h"
#include "selectScene.h"


selectScene::selectScene()
{
}


selectScene::~selectScene()
{

}

HRESULT selectScene::init()
{
	//======================================================================================================= 마리오1
	_Mario1.img = IMAGEMANAGER->findImage("shovelKnightSelect");
	_Mario1.x = 200;
	_Mario1.y = 500;
	_Mario1.rc = RectMake(_Mario1.x, _Mario1.y, _Mario1.img->getFrameWidth(), _Mario1.img->getFrameHeight());
	_Mario1.ani = new animation;
	_Mario1.ani->init(_Mario1.img->getWidth(), _Mario1.img->getHeight(),
						_Mario1.img->getFrameWidth(), _Mario1.img->getFrameHeight());
	int mario1AniArray[] = { 0 };
	_Mario1.ani->setPlayFrame(mario1AniArray, 1, false);
	_Mario1.ani->setFPS(1);
	//=======================================================================================================

	//======================================================================================================= 마리오2
	_Mario2.img = IMAGEMANAGER->findImage("shovelKnightSelect");
	_Mario2.x = 400;
	_Mario2.y = 500;
	_Mario2.rc = RectMake(_Mario2.x, _Mario2.y, _Mario2.img->getFrameWidth(), _Mario2.img->getFrameHeight());
	_Mario2.ani = new animation;
	_Mario2.ani->init(_Mario2.img->getWidth(), _Mario2.img->getHeight(),
						_Mario2.img->getFrameWidth(), _Mario2.img->getFrameHeight());
	int mario2AniArray[] = { 0 };
	_Mario2.ani->setPlayFrame(mario2AniArray, 1, false);
	_Mario2.ani->setFPS(1);
	//=======================================================================================================

	//======================================================================================================= 마리오3
	_Mario3.img = IMAGEMANAGER->findImage("shovelKnightSelect");
	_Mario3.x = 600;
	_Mario3.y = 500;
	_Mario3.rc = RectMake(_Mario3.x, _Mario3.y, _Mario3.img->getFrameWidth(), _Mario3.img->getFrameHeight());
	_Mario3.ani = new animation;
	_Mario3.ani->init(_Mario3.img->getWidth(), _Mario3.img->getHeight(),
						_Mario3.img->getFrameWidth(), _Mario3.img->getFrameHeight());
	int mario3AniArray[] = { 0 };
	_Mario3.ani->setPlayFrame(mario3AniArray, 1, false);
	_Mario3.ani->setFPS(1);
	//=======================================================================================================

	return S_OK;
}

void selectScene::release()
{

}

void selectScene::update() 
{
	//============================================================= 마리오1
	_Mario1.ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);

	if (!PtInRect(&_Mario1.rc, _ptMouse))
	{
	    //이미지 체인지
		int tanukiAniArray[] = { 0 };
		_Mario1.ani->setPlayFrame(tanukiAniArray, 1, false);	
	}
	else
	{
		//이미지 체인지
		int tanukiAniArray[] = { 1 };
		_Mario1.ani->setPlayFrame(tanukiAniArray, 1, false);

		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			SCENEMANAGER->changeScene("게임씬");
		}
	}
	//=============================================================

	//============================================================= 마리오2
	_Mario2.ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);

	if (!PtInRect(&_Mario2.rc, _ptMouse))
	{
		//이미지 체인지
		int tanukiAniArray[] = { 0 };
		_Mario2.ani->setPlayFrame(tanukiAniArray, 1, false);
	}
	else
	{
		//이미지 체인지
		int tanukiAniArray[] = { 1 };
		_Mario2.ani->setPlayFrame(tanukiAniArray, 1, false);

		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			SCENEMANAGER->changeScene("게임씬");
		}
	}
	//=============================================================

	//============================================================= 마리오3
	_Mario3.ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);

	if (!PtInRect(&_Mario3.rc, _ptMouse))
	{
		//이미지 체인지
		int tanukiAniArray[] = { 0 };
		_Mario3.ani->setPlayFrame(tanukiAniArray, 1, false);
	}
	else
	{
		//이미지 체인지
		int tanukiAniArray[] = { 1 };
		_Mario3.ani->setPlayFrame(tanukiAniArray, 1, false);

		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			SCENEMANAGER->changeScene("게임씬");
		}
	}
	//=============================================================

}

void selectScene::render() 
{
	//백그라운드 이미지
	IMAGEMANAGER->findImage("선택창")->render(getMemDC(), 0, 0);

	//=========================================================================================================== 마리오1
	//RECT
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _Mario1.rc.left, _Mario1.rc.top, _Mario1.rc.right, _Mario1.rc.bottom);
	}
	//마리오1 
	_Mario1.img->aniRender(getMemDC(), _Mario1.x, _Mario1.y, _Mario1.ani);
	//===========================================================================================================

	//=========================================================================================================== 마리오2
	//RECT
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _Mario2.rc.left, _Mario2.rc.top, _Mario2.rc.right, _Mario2.rc.bottom);
	}
	//마리오2
	_Mario2.img->aniRender(getMemDC(), _Mario2.x, _Mario2.y, _Mario2.ani);
	//===========================================================================================================

	//=========================================================================================================== 마리오3
	//RECT
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _Mario3.rc.left, _Mario3.rc.top, _Mario3.rc.right, _Mario3.rc.bottom);
	}
	//마리오3 
	_Mario3.img->aniRender(getMemDC(), _Mario3.x, _Mario3.y, _Mario3.ani);
	//===========================================================================================================

}


