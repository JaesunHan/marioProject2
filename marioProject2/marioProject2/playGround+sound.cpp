#include "stdafx.h"
#include "playGround.h"


void playGround::addSound(void)
{
	//사운드 추가
	SOUNDMANAGER->addSound("BGM", ".\\sound\\marioBgm.mp3", true, true);
	SOUNDMANAGER->addSound("enterGame", ".\\sound\\enterGame.wav", false, false);
	SOUNDMANAGER->addSound("marioJump", ".\\sound\\marioJump.wav", false, false);
	SOUNDMANAGER->addSound("marioDies", ".\\sound\\marioDies.wav", false, false);
	SOUNDMANAGER->addSound("GameOver", ".\\sound\\gameOver.wav", false, false);
	SOUNDMANAGER->addSound("menuEnter", ".\\sound\\opening_menuEnter.mp3", false, false);


	
	//BGM 그룹화 set



	//효과음 그룹화 set


}
