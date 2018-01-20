#pragma once
#include "gameNode.h"
#include "bullets.h"

class ship : public gameNode
{
protected:
	//GDIPLUS <-- 3�� �̻� �Ѹ��� �ް��ϰ� ������
	image* _image;
	RECT _rc;
	float _x, _y;
	float _angle;
	float _speed;
	float _radius;

	//�⺻ �Ѿ��� ��� �Լ����� ������ �� �ִ�
	bullet* _bullet;

public:
	ship();
	~ship();

	virtual HRESULT init(const char* imageName, int x, int y);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	virtual void draw(void);
	virtual void keyControl(void);
	virtual void move(void);

	virtual void bulletFire(void);
	virtual void bulletMove(void);
	virtual void bulletDraw(void);

	virtual void focusDraw(void);
	virtual void defaultDraw(RECT rcFocus);

	image* getImage() { return _image; }
	RECT getRect() { return _rc; }

	void setAngle(float angle) { _angle = angle; }
	float getAngle() { return _angle; }

};
