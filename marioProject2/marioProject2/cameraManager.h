#pragma once
#include "singletonBase.h"
#include "image.h"

class cameraManager : public singletonBase<cameraManager>
{
private:
	float _camX;
	float _camY;

	image* _bg;
	image* _pl;
	float _plX;
	float _plY;

public:
	cameraManager();
	~cameraManager() {};
	
	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);
	void render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//프레임 렌더
	void frameRender(string strKey, HDC hdc, int destX, int destY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	//루프렌더
	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY);

	//알파렌더
	void alphaRender(string strKey, HDC hdc, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);
	void alphaFrameRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);
	void alphaFrameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, BYTE alpha);
	void alphaLoopRender(string strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY, BYTE alpha);

	void aniRender(string strKey, HDC hdc, int destX, int destY, animation* ani);



	void getBackGroundMemory(image* img) { _bg = img; }

	void init(float playerX, float playerY);
	void update(float playerX, float playerY);



	//=================무쓸모=================
	void plusCamX(float& playerX, float addX);
	void plusCamY(float& playerY, float addY);


	float getX() { return _camX; }
	float getY() { return _camY; }
};