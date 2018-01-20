#include "stdafx.h"
#include "playGround.h"

void playGround::addImage()
{
	//타이틀
	IMAGEMANAGER->addImage("backGround(title)", ".//image//backGround(title).bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));

	//캐릭터 선택창
	IMAGEMANAGER->addImage("선택창", ".//image//characterSelect.bmp", 0, 0, 960, 720, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mario1", ".//image//shovelKnightSelect.bmp", 260, 134, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mario2", ".//image//tanukiMarioSelectImage.bmp", 192, 135, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mario3", ".//image//mario_basic_select.bmp", 154, 135, 2, 1, true, RGB(255, 0, 255));


	//플레이어
	IMAGEMANAGER->addFrameImage("베이지마리오대기_우", "./image/mario_basic_idle_right.bmp", 70, 135, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("베이지마리오대기_좌", "./image/mario_basic_idle_left.bmp", 70, 135, 1, 1, true, RGB(255, 0, 255));
}