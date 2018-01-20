#include "stdafx.h"
#include "playGround.h"

void playGround::addImage()
{
	

	

	IMAGEMANAGER->addImage("backGround(title)", ".//image//backGround(title).bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));


	//캐릭터 선택창
	IMAGEMANAGER->addImage("선택창", ".//image//characterSelect.bmp", 0, 0, 960, 720, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("shovelKnightSelect", ".//image//shovelKnightSelect.bmp", 260, 134, 2, 1, true, RGB(255, 0, 255));

}