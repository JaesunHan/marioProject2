#include "stdafx.h"
#include "enemy.h"
#include "player.h"



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
	_imgKeyString = imgKey;
	_anim = new animation;
	_anim->init(_img->getWidth(), _img->getHeight(), _img->getFrameWidth(), _img->getFrameHeight());
	_anim->setDefPlayFrame(false, true);
	_anim->setFPS(1);

	_icanseeyou = RectMakeCenter(_x+_img->getFrameWidth()/2, _y+_img->getFrameHeight()/2, _img->getFrameWidth() * 3, _img->getFrameHeight() * 1);

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
			_y += -sinf(_angle)*_spd;
			_icanseeyou = RectMakeCenter(_x + _img->getFrameWidth() / 2, _y + _img->getFrameHeight() / 2, _img->getFrameWidth() * 3, _img->getFrameHeight() * 1);
			//���⿡ ���� �ִϸ��̼��� �÷��� �� ����
			switch (_direction)
			{
			//�������� ����
			case ENEMYLEFT:
				//_angle = PI;
				_anim->setPlayFrame((_img->getMaxFrameX() + 1)*ENEMYLEFT, (_img->getMaxFrameX() + 1) * (ENEMYLEFT + 1) - 1, false, true);
				_anim->frameUpdate(TIMEMANAGER->getElapsedTime() * 8);
				break;
			//���������� ����
			case ENEMYRIGHT:
				//_angle = PI2;
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
				_angle = PI2;
			}
			if (_x+_img->getFrameWidth() >= WINSIZEX)
			{
				_x = WINSIZEX- _img->getFrameWidth();
				_direction = ENEMYLEFT;
				_angle = PI;
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
	//_img->aniRender(hdc, _x, _y, _anim);
	CAMERAMANAGER->aniRender(_imgKeyString, hdc, _x, _y, _anim);
}
void enemy::startAnim()
{
	_anim->start();
}

float enemy::followPlayer(player* p)
{
	RECT rc;
	//���� �þ� �ȿ� �÷��̾ ������
	if (IntersectRect(&rc, &p->getRect(), &_icanseeyou))
	{
		_angle = getAngle(_x + _img->getFrameWidth() / 2, _y + _img->getFrameHeight() / 2, p->getX(), p->getY());
		//�ޱ��� 2, 3 ��и� �϶�
		if (_angle < (PI / 2 * 3) && _angle >= PI / 2)
		{
			//������ �����̹Ƿ� �������� �����̴� �׸��� ����ؾߵ�
			_direction = ENEMYLEFT;
			//�������� ���ٰ� �÷��̾�� �ε����� ���������� �о��
			if (_x <= p->getX() + (p->getRect().right - p->getRect().left))
			{
				_x = p->getX() + (p->getRect().right - p->getRect().left);
			}
		}
		else
		{
			//������ �������̹Ƿ� ���������� �����̴� �׸��� ����ؾߵ�
			_direction = ENEMYRIGHT;
			//���������� ���ٰ� �÷��̾�� �ε����� �������� �о��
			if (_x >= p->getX())
			{
				_x = p->getX();
			}

		}
	}
	//���� �þ߾ȿ� �÷��̾ �ȵ���������
	//else 
	//{
	//	_direction = ENEMYRIGHT;
	//	_angle = PI2;
	//}
	


	return _angle;
}