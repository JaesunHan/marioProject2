#include "stdafx.h"
#include "playGround.h"

void playGround::addImage()
{
	//Ÿ��Ʋ
	IMAGEMANAGER->addImage("backGround(title)", ".//image//backGround(title).bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));

	//ĳ���� ����â
	IMAGEMANAGER->addImage("����â", ".//image//characterSelect.bmp", 0, 0, 960, 720, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mario1", ".//image//shovelKnightSelect.bmp", 260, 134, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mario2", ".//image//tanukiMarioSelectImage.bmp", 192, 135, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mario3", ".//image//mario_basic_select.bmp", 154, 135, 2, 1, true, RGB(255, 0, 255));


	//�÷��̾�

	IMAGEMANAGER->addFrameImage("���������������_��", "./image/mario_basic_idle_right.bmp", 70, 135, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���������������_��", "./image/mario_basic_idle_left.bmp", 70, 135, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����������������_��", "./image/mario_basic_move_left.bmp", 160, 135, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����������������_��", "./image/mario_basic_move_right.bmp", 160, 135, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����������������_��", "./image/mario_basic_jump_left.bmp", 83, 135, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����������������_��", "./image/mario_basic_jump_right.bmp", 83, 135, 1, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("tanukiMarioBasicAttack", ".\\image\\tanukiMarioBasicAttack.bmp", 135, 270, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tanukiMarioIdle", ".\\image\\tanukiMarioIdle.bmp", 126, 270, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tanukiMarioJump", ".\\image\\tanukiMarioJump.bmp", 135, 270, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tanukiMarioRunning", ".\\image\\tanukiMarioRunning.bmp", 260, 270, 2, 2, true, RGB(255, 0, 255));



}