#include "stdafx.h"
#include "cameraManager.h"
#include "imageManager.h"

cameraManager::cameraManager()
	: _camX(0),
	_camY(0)
{	
}

void cameraManager::render(string strKey, HDC hdc)
{
	image* img = IMAGEMANAGER->findImage(strKey);

	if (img) img->render(hdc);
}

void cameraManager::render(string strKey, HDC hdc, int destX, int destY)
{
	image* img = IMAGEMANAGER->findImage(strKey);

	if (img) img->render(hdc, destX - _camX, destY - _camY);
}

void cameraManager::render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	image* img = IMAGEMANAGER->findImage(strKey);

	if (img) img->render(hdc, destX - _camX, destY - _camY, sourX, sourY, sourWidth, sourHeight);
}

void cameraManager::frameRender(string strKey, HDC hdc, int destX, int destY)
{
	image* img = IMAGEMANAGER->findImage(strKey);

	if (img) img->frameRender(hdc, destX - _camX, destY - _camY);
}

void cameraManager::frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	image* img = IMAGEMANAGER->findImage(strKey);

	if (img) img->frameRender(hdc, destX - _camX, destY - _camY, currentFrameX, currentFrameY);
}

void cameraManager::loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY)
{
	image* img = IMAGEMANAGER->findImage(strKey);

	if (img) img->loopRender(hdc, drawArea, offSetX - _camX, offSetY - _camY);
}

void cameraManager::alphaRender(string strKey, HDC hdc, BYTE alpha)
{
	image* img = IMAGEMANAGER->findImage(strKey);

	if (img) img->alphaRender(hdc, alpha);
}

void cameraManager::alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha)
{
	image* img = IMAGEMANAGER->findImage(strKey);

	if (img) img->alphaRender(hdc, destX - _camX, destY - _camY, alpha);
}

void cameraManager::alphaFrameRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha)
{
	image* img = IMAGEMANAGER->findImage(strKey);

	if (img) img->alphaFrameRender(hdc, destX - _camX, destY - _camY, alpha);
}

void cameraManager::alphaFrameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, BYTE alpha)
{
	image* img = IMAGEMANAGER->findImage(strKey);

	if (img) img->alphaFrameRender(hdc, destX - _camX, destY - _camY, currentFrameX, currentFrameY, alpha);
}

void cameraManager::alphaLoopRender(string strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY, BYTE alpha)
{
	image* img = IMAGEMANAGER->findImage(strKey);

	if (img) img->alphaLoopRender(hdc, drawArea, offSetX - _camX, offSetY - _camY, alpha);
}

void cameraManager::aniRender(string strKey, HDC hdc, int destX, int destY, animation * ani)
{
	image* img = IMAGEMANAGER->findImage(strKey);

	if (img) img->aniRender(hdc, destX - _camX, destY - _camY, ani);
}


void cameraManager::setCameraXY(float x, float y)
{
	_camX = x - WINSIZEX / 2;
	_camY = y - WINSIZEY / 2;
}

void cameraManager::plusCamX(float& playerX, float addX)
{
	playerX += addX;

	if (WINSIZEX / 2 < playerX
		&& _bg->getWidth() - WINSIZEX / 2 > playerX)
	{
		_camX += addX;
	}

	if (_camX < 0)
	{
		_camX = 0;
	}
	if (_camX > _bg->getWidth() - WINSIZEX)
	{
		_camX = _bg->getWidth() - WINSIZEX;
	}
}

void cameraManager::plusCamY(float& playerY, float addY)
{
	playerY += addY;

	if (WINSIZEY / 2 < playerY
		&& _bg->getHeight() - WINSIZEY / 2 > playerY)
	{
		_camY += addY;
	}

	if (_camY < 0)
	{
		_camY = 0;
	}
	if (_camY > _bg->getHeight() - WINSIZEY)
	{
		_camY = _bg->getHeight() - WINSIZEY;
	}
}
