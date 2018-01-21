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

	IMAGEMANAGER->addFrameImage("베이직마리오대기_우", "./image/mario_basic_idle_right.bmp", 70, 135, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("베이직마리오대기_좌", "./image/mario_basic_idle_left.bmp", 70, 135, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("베이직마리오무브_좌", "./image/mario_basic_move_left.bmp", 160, 135, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("베이직마리오무브_우", "./image/mario_basic_move_right.bmp", 160, 135, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("베이직마리오점프_좌", "./image/mario_basic_jump_left.bmp", 83, 135, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("베이직마리오점프_우", "./image/mario_basic_jump_right.bmp", 83, 135, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tanukiMarioBasicAttack", ".\\image\\tanukiMarioBasicAttack.bmp", 135, 270, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tanukiMarioIdle", ".\\image\\tanukiMarioIdle.bmp", 126, 270, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tanukiMarioJump", ".\\image\\tanukiMarioJump.bmp", 135, 270, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tanukiMarioRunning", ".\\image\\tanukiMarioRunning.bmp", 260, 270, 2, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("sKnightIdleL", ".\\image\\sKnightIdleL.bmp", 260, 134, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("sKnightIdleR", ".\\image\\sKnightIdleR.bmp", 260, 134, 1, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("sKnightAttackL", ".\\image\\sKnightAttackL.bmp", 1035, 134, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("sKnightAttackR", ".\\image\\sKnightAttackR.bmp", 1035, 134, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("sKnightJumpL", ".\\image\\sKnightJumpL.bmp", 390, 134, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("sKnightJumpR", ".\\image\\sKnightJumpR.bmp", 390, 134, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("sKnightWalkL", ".\\image\\sKnightWalkL.bmp", 1200, 201, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("sKnightWalkR", ".\\image\\sKnightWalkR.bmp", 1200, 201, 6, 1, true, RGB(255, 0, 255));



}