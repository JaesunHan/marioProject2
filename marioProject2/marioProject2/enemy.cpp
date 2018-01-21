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

	_rc = RectMake(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
	_icanseeyou = RectMakeCenter(_x+_img->getFrameWidth()/2, _y+_img->getFrameHeight()/2, _img->getFrameWidth() * 3, _img->getFrameHeight() * 1);
	_moveArea = RectMakeCenter(_x + _img->getFrameWidth() / 2, _y + _img->getFrameHeight() / 2, WINSIZEX - 100, _img->getFrameHeight());

	//���� ������
	_probe[0] = PointMake(_x, _y);
	_probe[1] = PointMake(_x + _img->getFrameWidth()/2, _y);
	_probe[2] = PointMake(_x + _img->getFrameWidth(), _y);
	_probe[3] = PointMake(_x, _y + _img->getFrameHeight() / 2);
	_probe[4] = PointMake(_x + _img->getFrameWidth(), _y + _img->getFrameHeight()/2);
	_probe[5] = PointMake(_x, _y + _img->getFrameHeight());
	_probe[6] = PointMake(_x + _img->getFrameWidth() / 2, _y + _img->getFrameHeight());
	_probe[7] = PointMake(_x + _img->getFrameWidth(), _y + _img->getFrameHeight());

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
			//_y += -sinf(_angle)*_spd;
			
			//���⿡ ���� �ִϸ��̼��� �÷��� �� ����
			switch (_direction)
			{
			//�������� ����
			case ENEMYLEFT:
				
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
			
			//���� ������ �� �ִ� ���� ������ �������� �ϸ� �о�� ���� �ٲٱ�
			if (_x <= _moveArea.left)
			{
				_x = _moveArea.left;
				_direction = ENEMYRIGHT;
				_angle = PI2;
			}
			if (_x+_img->getFrameWidth() >= _moveArea.right)
			{
				_x = _moveArea.right - _img->getFrameWidth();
				_direction = ENEMYLEFT;
				_angle = PI;
			}

		}
	}
	//���� ������
	_probe[0] = PointMake(_x, _y);
	_probe[1] = PointMake(_x + _img->getFrameWidth() / 2, _y);
	_probe[2] = PointMake(_x + _img->getFrameWidth(), _y);
	_probe[3] = PointMake(_x, _y + _img->getFrameHeight() / 2);
	_probe[4] = PointMake(_x + _img->getFrameWidth(), _y + _img->getFrameHeight() / 2);
	_probe[5] = PointMake(_x, _y + _img->getFrameHeight());
	_probe[6] = PointMake(_x + _img->getFrameWidth() / 2, _y + _img->getFrameHeight());
	_probe[7] = PointMake(_x + _img->getFrameWidth(), _y + _img->getFrameHeight());
	_icanseeyou = RectMakeCenter(_x + _img->getFrameWidth() / 2, _y + _img->getFrameHeight() / 2, _img->getFrameWidth() * 3, _img->getFrameHeight() * 1);
	//�ȼ��浹
	pixelCollisionFloor();
	
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
			if (_x <= p->getX()- CAMERAMANAGER->getX() + (p->getRect().right - p->getRect().left))
			{
				_x = p->getX()- CAMERAMANAGER->getX() + (p->getRect().right - p->getRect().left);
				
			}
		}
		else
		{
			//������ �������̹Ƿ� ���������� �����̴� �׸��� ����ؾߵ�
			_direction = ENEMYRIGHT;
			//���������� ���ٰ� �÷��̾�� �ε����� �������� �о��
			if (_x >= p->getX()-CAMERAMANAGER->getX())
			{
				
				_x = p->getX()- CAMERAMANAGER->getX();
			}
		}
	}
	
	
	

	return _angle;
}

void enemy::pixelCollisionFloor()
{
	
	for (int p = 0; p < MAXPROBE; p++)
	{
		for (int i = _probe[p].y - 10; i < _probe[p].y + 10; ++i)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("���Ӿ����̾ƿ�")->getMemDC(), _probe[p].x, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if (!(r == 255 && g == 0 && b == 255))
			{
				_y = i - _img->getHeight() / 2;
				break;
			}

		}
	}
	
}