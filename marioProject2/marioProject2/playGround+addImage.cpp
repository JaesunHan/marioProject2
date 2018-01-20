#include "stdafx.h"
#include "playGround.h"

void playGround::addImage()
{
	
	IMAGEMANAGER->addImage("바탕", "우주.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("battle", "battle.bmp", 0, 0, 1536, 79, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("battle2", "battle.bmp", 0, 0, 1536, 79, 16, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("bullet", "bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("missilePF", "missilePF.bmp", 0, 0, 576, 44, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("버튼", "button.bmp", 0, 0, 122, 62, 1, 2, true, RGB(255, 0, 255));
	

	IMAGEMANAGER->addImage("backGround(title)", "backGround(title).bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));





}