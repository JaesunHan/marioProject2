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
	_Mario1.img = IMAGEMANAGER->findImage("mario1");
	_Mario1.x = 220;
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
	_Mario2.img = IMAGEMANAGER->findImage("mario2");
	_Mario2.x = 420;
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
	_Mario3.img = IMAGEMANAGER->findImage("mario3");
	_Mario3.x = 620;
	_Mario3.y = 500;
	_Mario3.rc = RectMake(_Mario3.x, _Mario3.y, _Mario3.img->getFrameWidth(), _Mario3.img->getFrameHeight());
	_Mario3.ani = new animation;
	_Mario3.ani->init(_Mario3.img->getWidth(), _Mario3.img->getHeight(),
						_Mario3.img->getFrameWidth(), _Mario3.img->getFrameHeight());
	int mario3AniArray[] = { 0 };
	_Mario3.ani->setPlayFrame(mario3AniArray, 1, false);
	_Mario3.ani->setFPS(1);
	//=======================================================================================================

	//선택된 캐릭터를 저장할 변수
	_selectPlayer = SELECT_NONE;

	//효과음 플레이 한번만 하도록
	_selectSoundPlay = false;

	//입장 효과음
	SOUNDMANAGER->play("menuEnter");

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

		_selectPlayer = SELECT_NONE;
	}
	else
	{
		//이미지 체인지
		int tanukiAniArray[] = { 1 };
		_Mario1.ani->setPlayFrame(tanukiAniArray, 1, false);
		_selectPlayer = SELECT_MARIO1;


		//효과음 play
		if (!SOUNDMANAGER->isPlaySound("marioJump") && !_selectSoundPlay)
		{
			_selectSoundPlay = true;
			SOUNDMANAGER->play("marioJump");
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
		_selectPlayer = SELECT_MARIO2;


		//효과음 play
		if (!SOUNDMANAGER->isPlaySound("marioJump") && !_selectSoundPlay)
		{
			_selectSoundPlay = true;
			SOUNDMANAGER->play("marioJump");
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
		_selectPlayer = SELECT_MARIO3;

		//효과음 play
		if (!SOUNDMANAGER->isPlaySound("marioJump") && !_selectSoundPlay)
		{
			_selectSoundPlay = true;
			SOUNDMANAGER->play("marioJump");
		}


	}
	//=============================================================


	//효과음 초기화
	if (!SOUNDMANAGER->isPlaySound("marioJump") && _selectPlayer == SELECT_NONE)
	{
		_selectSoundPlay = false;
	}

	saveTxt();
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


	//=========================================================================================================== 테스트 출력
	testRender(getMemDC(), "_selectPlayer: ", VK_TAB, _selectPlayer, 10, 100);
	testRender(getMemDC(), "_selectSoundPlay: ", VK_TAB, _selectSoundPlay, 10, 120);
}

void selectScene::saveTxt()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		switch (_selectPlayer)
		{
		case SELECT_NONE:
			break;
		case SELECT_MARIO1:
		{
			char temp[128];
			vector<string> vStr;

			vStr.push_back("플레이어");
			vStr.push_back(itoa(1, temp, 10));

			TXTDATA->txtSave("save22", vStr);

			SCENEMANAGER->changeScene("게임씬");
		}
			break;
		case SELECT_MARIO2:
		{
			char temp[128];
			vector<string> vStr;

			vStr.push_back("플레이어");
			vStr.push_back(itoa(2, temp, 10));

			TXTDATA->txtSave("save22", vStr);
			SCENEMANAGER->changeScene("게임씬");

		}
			break;
		case SELECT_MARIO3:
		{
			char temp[128];
			vector<string> vStr;

			vStr.push_back("플레이어");
			vStr.push_back(itoa(3, temp, 10));
			TXTDATA->txtSave("save22", vStr);

			SCENEMANAGER->changeScene("게임씬");
		}
			break;
		}
	}
}

