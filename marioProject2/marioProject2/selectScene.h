#pragma once
#include "gameNode.h"
#include "button.h"
#include "action.h"

//선택 캐릭터 구조체
struct tagPlayer
{
	image* img;               //선택 이미지
	RECT rc;                  //활성화 렉트
	int x, y;                 //위치좌표X, Y
	animation* ani;           //활성화 에니메이션
};

class selectScene : public gameNode
{
private:
	image* _selectBg;        //선택씬 백그라운드 이미지
	tagPlayer _Mario1;  //마리오1
	tagPlayer _Mario2;  //마리오1
	tagPlayer _Mario3;  //마리오1





public:
	HRESULT init();
	void release();
	void update();
	void render();

	//전역으로 되어있어서 static으로 해줬다(콜백함수에 사용될 함수)
	static void cbSceneChange();
	


	selectScene();
	~selectScene();
};

