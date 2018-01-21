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

	//적의 왼쪽위
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
	
	// 애니메이션 정보가 있으면
	if (_anim != NULL)
	{
		//적이 걷는 상태이면
		if (_status == ENEMYWALK) 
		{
			
			//움직이기
			_x += cosf(_angle)*_spd;
			_y += -sinf(_angle)*_spd;
			_icanseeyou = RectMakeCenter(_x + _img->getFrameWidth() / 2, _y + _img->getFrameHeight() / 2, _img->getFrameWidth() * 3, _img->getFrameHeight() * 1);
			//방향에 따라 애니메이션의 플레이 셋 변경
			switch (_direction)
			{
			//왼쪽으로 갈때
			case ENEMYLEFT:
				//_angle = PI;
				_anim->setPlayFrame((_img->getMaxFrameX() + 1)*ENEMYLEFT, (_img->getMaxFrameX() + 1) * (ENEMYLEFT + 1) - 1, false, true);
				_anim->frameUpdate(TIMEMANAGER->getElapsedTime() * 8);
				break;
			//오른쪽으로 갈때
			case ENEMYRIGHT:
				//_angle = PI2;
				_anim->setPlayFrame((_img->getMaxFrameX() + 1)*ENEMYRIGHT, (_img->getMaxFrameX()+1) * (ENEMYRIGHT + 1) - 1, false, true);
				_anim->frameUpdate(TIMEMANAGER->getElapsedTime() * 8);
				break;
			default:
				break;
			}
			
			//화면 밖에 나가려고 하면 밀어내고 방향 바꾸기
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
	//적의 시야 안에 플레이어가 들어오면
	if (IntersectRect(&rc, &p->getRect(), &_icanseeyou))
	{
		_angle = getAngle(_x + _img->getFrameWidth() / 2, _y + _img->getFrameHeight() / 2, p->getX(), p->getY());
		//앵글이 2, 3 사분면 일때
		if (_angle < (PI / 2 * 3) && _angle >= PI / 2)
		{
			//방향은 왼쪽이므로 왼쪽으로 움직이는 그림을 출력해야됨
			_direction = ENEMYLEFT;
			//왼쪽으로 가다가 플레이어랑 부딪히면 오른쪽으로 밀어내기
			if (_x <= p->getX()- CAMERAMANAGER->getX() + (p->getRect().right - p->getRect().left))
			{
				
				_x = p->getX()- CAMERAMANAGER->getX() + (p->getRect().right - p->getRect().left);
			}
		}
		else
		{
			//방향은 오른쪽이므로 오른쪽으로 움직이는 그림을 출력해야됨
			_direction = ENEMYRIGHT;
			//오른쪽으로 가다가 플레이어랑 부딪히면 왼쪽으로 밀어내기
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

<<<<<<< HEAD
			if (!(r == 255 && g == 0 && b == 255))
			{
				_y = i - _img->getHeight() / 2;
				break;
			}

		}
	}
	
=======
>>>>>>> 9fe46569239634daeb5529e2745db4111f839010
}