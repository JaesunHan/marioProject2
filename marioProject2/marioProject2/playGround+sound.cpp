#include "stdafx.h"
#include "playGround.h"


void playGround::addSound(void)
{
	//���� �߰�
	SOUNDMANAGER->addSound("BGM", ".\\sound\\marioBgm.mp3", true, true);
	SOUNDMANAGER->addSound("enterGame", ".\\sound\\enterGame.wav", false, false);
	SOUNDMANAGER->addSound("marioJump", ".\\sound\\marioJump.wav", false, false);
	SOUNDMANAGER->addSound("marioDies", ".\\sound\\marioDies.wav", false, false);
	SOUNDMANAGER->addSound("GameOver", ".\\sound\\gameOver.wav", false, false);
	SOUNDMANAGER->addSound("menuEnter", ".\\sound\\opening_menuEnter.mp3", false, false);


	
	//BGM �׷�ȭ set



	//ȿ���� �׷�ȭ set


}
