#pragma once
#pragma warning(disable:2397)

#define MAPSIZEX 1067.f
#define MAPSIZEY 1800.f

#define SMALLX		WINSIZEX / MAPSIZEX 
#define SMALLY		WINSIZEY / MAPSIZEY 
#define BIGX		MAPSIZEX / WINSIZEX 
#define BIGY		MAPSIZEY / WINSIZEY

#define MAZEN COLORREF RGB(255,0,255)

#define BUFFER 128


namespace Ʈ��������
{
	typedef struct tagFloatPoint
	{
		float x;
		float y;
	} FPOINT;

	typedef struct tagZOrderObject
	{
		image* img;
		FPOINT ptImage;
		FPOINT z;
	} ZOO;

	typedef vector<tagZOrderObject> vZOO;
	typedef vector<tagZOrderObject>::iterator viZOO;
	typedef map<float, int> mZOO;
	typedef map<float, int>::iterator miZOO;

	//��+�׸� �浹
	BOOL isCollisionEllRect(RECT rcEll, RECT rcRect);

	//��+�� �浹
	BOOL isCollisionEllEll(RECT rcEll1, RECT rcEll2);

	//FPT������ �Ÿ�
	float getDistancePoint(FPOINT ptStart, FPOINT ptEnd);

	float getDistancePoint(POINT ptStart, POINT ptEnd);

	//FPT������ ����
	float getAnglePoint(FPOINT pt1, FPOINT pt2);

	float getAnglePoint(POINT pt1, POINT pt2);

	//PT�� ���ȿ� ������
	BOOL PtInEll(RECT rc, FPOINT pt);

	BOOL PtInEll(RECT rc, POINT pt);

	//PT�� �׸�ȿ� ������
	BOOL PtInRc(RECT rc, FPOINT pt);

	BOOL PtInRc(RECT rc, POINT pt);

	//FPT ����� ��ũ��
	FPOINT FPointMake(float x, float y);

	//��Ʈ left top�� FPT�� �����
	FPOINT FPointMakeRectLT(RECT rc);

	//��Ʈ �߽ɿ� FPT�� �����
	FPOINT FPointMakeRectCC(RECT rc);

	POINT PointMakeRectLT(RECT rc);

	POINT PointMakeRectCC(RECT rc);

	//
	RECT RectMakePoint(FPOINT pt, float width, float height);

	RECT RectMakePoint(POINT pt, float width, float height);
	
	RECT RectMakePointCC(FPOINT pt, float width, float height);

	RECT RectMakePointCC(POINT pt, float width, float height);

	RECT RectMakePointCB(FPOINT pt, float width, float height);


	RECT RectMakePointCB(POINT pt, float width, float height);

	void RectangleMakeRect(HDC hdc, RECT rc, float x = 0, float y = 0);

	void EllipseMakeRect(HDC hdc, RECT rc);

	//��Ʈ ũ�� �޾ƿ���
	float getRectWidth(RECT rc);

	float getRectHeight(RECT rc);


	//FPt, width, height�� ��Ʈ left top �޾ƿ���

	//left
	float getRectLeft(FPOINT pt, float width);

	//top
	float getRectTop(FPOINT pt, float height);

	float getRectLeft(POINT pt, float width);

	float getRectTop(POINT pt, float height);

	//FPOINT left top
	FPOINT getFPointLT(FPOINT pt, float width, float height);

	//POINT�� �ϸ� ���ս��� �Ͼ�� FPOINT�� �����
	void PtMoveAngleSpeed(FPOINT& pt, float angle, float speed);

	void XYMoveAngleSpeed(float& x, float& y, float angle, float speed);

	void PtMoveSpeed(FPOINT& pt, float speedX, float speedY);

	void XYMoveSpeed(float& x, float& y, float speedX, float speedY);

	void RectMoveSpeed(RECT& rc, float speedX, float speedY);

	// hdc, x��ǥ, y��ǥ, ǥ�����ؽ�Ʈ"", ǥ���Ұ�, ���ǥ�ÿ���		":"�� �ڵ����� ����
	void TTTextOut(HDC hdc, int x, int y, char* stri, float f, bool backGround = true);

	void TTTextOut(HDC hdc, int x, int y, char* stri, int d, bool backGround = true);

	void TTTextOut(float f);

	//x, y �ȼ��� ��������?
	BOOL ThisPixelIsMazen(HDC hdc, int x, int y);

	RECT RectMakeSmall(RECT rc);

	RECT RectMakeBig(RECT rc);

	FPOINT PointMakeSmall(FPOINT pt);

	FPOINT PointMakeBig(FPOINT pt);

	int getbuffer10(float var);

	int getbuffer01(float var);


}

