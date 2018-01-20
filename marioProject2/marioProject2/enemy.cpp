#include "stdafx.h"
#include "enemy.h"



enemy::enemy()
{

}

enemy::~enemy()
{

}

HRESULT enemy::init(string imgKey, char* imgFileName, float x, float y, int totalWidth, int totalHeight, int frameNumX, int frameNumY)
{
	_img = IMAGEMANAGER->addFrameImage(imgKey, imgFileName, totalWidth, totalHeight, frameNumX, frameNumY, true, RGB(255, 0, 255));
	_x = x;
	_y = y;
	_anim = new animation;
	_anim->init(_img->getWidth(), _img->getHeight(), _img->getFrameWidth(), _img->getFrameHeight());
	_anim->setDefPlayFrame(false, true);
	_anim->setFPS(1);


	return S_OK;
}
void enemy::update() 
{
	
	// �ִϸ��̼� ������ ������
	if (_anim != NULL)
	{
		//���� �ȴ� �����̸�
		if (_status == ENEMYWALK) 
		{
			//�����̱�
			_x += cosf(_angle)*_spd;

			//���⿡ ���� �ִϸ��̼��� �÷��� �� ����
			switch (_direction)
			{
			//�������� ����
			case ENEMYLEFT:
				_angle = PI;
				_anim->setPlayFrame((_img->getMaxFrameX() + 1)*ENEMYLEFT, (_img->getMaxFrameX() + 1) * (ENEMYLEFT + 1) - 1, false, true);
				_anim->frameUpdate(TIMEMANAGER->getElapsedTime() * 8);
				break;
			//���������� ����
			case ENEMYRIGHT:
				_angle = PI2;
				_anim->setPlayFrame((_img->getMaxFrameX() + 1)*ENEMYRIGHT, (_img->getMaxFrameX()+1) * (ENEMYRIGHT + 1) - 1, false, true);
				_anim->frameUpdate(TIMEMANAGER->getElapsedTime() * 8);
				break;
			default:
				break;
			}
			
			//ȭ�� �ۿ� �������� �ϸ� �о�� ���� �ٲٱ�
			if (_x <= 0)
			{
				_x = 0;
				_direction = ENEMYRIGHT;
			}
			if (_x+_img->getFrameWidth() >= WINSIZEX)
			{
				_x = WINSIZEX- _img->getFrameWidth();
				_direction = ENEMYLEFT;

			}
		}
	}
	
	
}
void enemy::release()
{

}
void enemy::render() 
{
	draw(getMemDC());
}
void enemy::draw(HDC hdc)	 
{
	_img->aniRender(hdc, _x, _y, _anim);
}
void enemy::startAnim()
{
	_anim->start();
}