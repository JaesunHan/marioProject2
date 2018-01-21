#pragma once
#include "gameNode.h"
#include "button.h"
#include "action.h"

//캐릭터 선택 구조체
struct tagPlayer
{
	image* img;               //선택 이미지
	RECT rc;                  //활성화 렉트
	int x, y;                 //위치좌표X, Y
	animation* ani;           //활성화 에니메이션
};

//선택된 캐릭터
enum PLAYER_SELETCT
{
	SELECT_NONE,
	SELECT_MARIO1,
	SELECT_MARIO2,
	SELECT_MARIO3
};

class selectScene : public gameNode
{
private:
	image* _selectBg;   //선택씬 백그라운드 이미지
	tagPlayer _Mario1;  //마리오1
	tagPlayer _Mario2;  //마리오2
	tagPlayer _Mario3;  //마리오3

	int _selectPlayer;   //선택된 캐릭터 상태
	bool _selectSoundPlay;



public:
	HRESULT init();
	void release();
	void update();
	void render();

	
	//============================================================= 접근자
	inline int getSelectPlayer() { return _selectPlayer; }

	selectScene();
	~selectScene();
};

