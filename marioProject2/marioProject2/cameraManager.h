#pragma once
#include "singletonBase.h"
#include "image.h"

class cameraManager : public singletonBase<cameraManager>
{
private:
	float _camX;
	float _camY;

	image* _bg;

	RECT _rcCamera;

public:
	cameraManager();
	~cameraManager() {};
	
	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);
	void render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//ÇÁ·¹ÀÓ ·»´õ
	void frameRender(string strKey, HDC hdc, int destX, int destY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	//·çÇÁ·»´õ
	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY);

	//¾ËÆÄ·»´õ
	void alphaRender(string strKey, HDC hdc, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);
	void alphaFrameRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);
	void alphaFrameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, BYTE alpha);
	void alphaLoopRender(string strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY, BYTE alpha);

	void aniRender(string strKey, HDC hdc, int destX, int destY, animation* ani);

	void setCameraXY(float x, float y);

	void plusCamX(float& playerX, float addX);
	void plusCamY(float& playerY, float addY);

	void getBackGroundMemory(image* img) { _bg = img; }

	float getX() { return _camX; }
	float getY() { return _camY; }
};