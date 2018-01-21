#include "stdafx.h"
#include "TTUtils.h"


namespace 트윈테일쟝
{
	BOOL isCollisionEllRect(RECT rcEll, RECT rcRect)
	{
		RECT ell = rcEll;
		RECT rc = rcRect;

		POINT ptell = PointMakeRectCC(ell);

		if (rc.left <= ptell.x && ptell.x <= rc.right
			|| rc.top <= ptell.y && ptell.y <= rc.bottom)
		{
			RECT temp;

			long radius = getRectWidth(ell) / 2;

			temp.left = rc.left - radius;
			temp.top = rc.top - radius;
			temp.right = rc.right + radius;
			temp.bottom = rc.bottom + radius;

			if (PtInRc(temp, ptell)) return TRUE;
		}

		//모서리조건
		if (PtInEll(ell, PointMake(rc.left, rc.top))) return TRUE;

		if (PtInEll(ell, PointMake(rc.left, rc.bottom))) return TRUE;

		if (PtInEll(ell, PointMake(rc.right, rc.top))) return TRUE;

		if (PtInEll(ell, PointMake(rc.right, rc.bottom))) return TRUE;

		return FALSE;
	}

	BOOL isCollisionEllEll(RECT rcEll1, RECT rcEll2)
	{
		long ell1Radius = getRectWidth(rcEll1) / 2;
		long ell2Radius = getRectWidth(rcEll2) / 2;

		POINT ell1pt = PointMakeRectCC(rcEll1);
		POINT ell2pt = PointMakeRectCC(rcEll2);

		if (ell1Radius + ell2Radius >= getDistancePoint(ell1pt, ell2pt))
		{
			return TRUE;
		}

		return FALSE;
	}

	float getDistancePoint(FPOINT ptStart, FPOINT ptEnd)
	{
		float x = ptEnd.x - ptStart.x;
		float y = ptEnd.y - ptStart.y;

		return sqrtf(x * x + y * y);
	}

	float getDistancePoint(POINT ptStart, POINT ptEnd)
	{
		long x = ptEnd.x - ptStart.x;
		long y = ptEnd.y - ptStart.y;

		return sqrtf(x * x + y * y);
	}

	float getAnglePoint(FPOINT pt1, FPOINT pt2)
	{
		float x = pt2.x - pt1.x;
		float y = pt2.y - pt1.y;

		float angle = acosf(x / sqrtf(x * x + y * y));

		if (pt2.y > pt1.y)
		{
			angle = PI2 - angle;
		}

		while (angle >= PI2) angle -= PI2;
		while (angle < 0) angle += PI2;

		return angle;
	}

	float getAnglePoint(POINT pt1, POINT pt2)
	{
		float x = pt2.x - pt1.x;
		float y = pt2.y - pt1.y;

		float angle = acosf(x / sqrtf(x * x + y * y));

		if (pt2.y > pt1.y)
		{
			angle = PI2 - angle;
		}

		while (angle >= PI2) angle -= PI2;
		while (angle < 0) angle += PI2;

		return angle;
	}

	BOOL PtInEll(RECT rc, FPOINT pt)
	{
		FPOINT ptRc = FPointMakeRectCC(rc);

		if (getDistancePoint(ptRc, pt) <= getRectWidth(rc) / 2)
		{
			return TRUE;
		}

		return FALSE;
	}

	BOOL PtInEll(RECT rc, POINT pt)
	{
		POINT ptRc = PointMakeRectCC(rc);

		if (getDistancePoint(ptRc, pt) <= getRectWidth(rc) / 2)
		{
			return TRUE;
		}

		return FALSE;
	}

	BOOL PtInRc(RECT rc, FPOINT pt)
	{
		if (rc.left <= pt.x && pt.x <= rc.right
			&& rc.top <= pt.y && pt.y <= rc.bottom)
		{
			return TRUE;
		}
		return FALSE;
	}

	BOOL PtInRc(RECT rc, POINT pt)
	{
		if (rc.left <= pt.x && pt.x <= rc.right
			&& rc.top <= pt.y && pt.y <= rc.bottom)
		{
			return TRUE;
		}
		return FALSE;
	}

	FPOINT FPointMake(float x, float y)
	{
		FPOINT pt = { x, y };

		return pt;
	}

	FPOINT FPointMakeRectLT(RECT rc)
	{
		return FPointMake(rc.left, rc.top);
	}

	FPOINT FPointMakeRectCC(RECT rc)
	{
		float x1 = rc.left + rc.right;
		float x2 = x1 / 2;
		float y1 = rc.top + rc.bottom;
		float y2 = y1 / 2;

		return FPointMake(x2, y2);
	}

	POINT PointMakeRectLT(RECT rc)
	{
		return PointMake(rc.left, rc.top);
	}

	POINT PointMakeRectCC(RECT rc)
	{
		float x1 = rc.left + rc.right;
		float x2 = x1 / 2;
		float y1 = rc.top + rc.bottom;
		float y2 = y1 / 2;
		
		return PointMake(x2, y2);
	}

	RECT RectMakePoint(FPOINT pt, float width, float height)
	{
		return {
			long(pt.x),
			long(pt.y),
			long(pt.x + width),
			long(pt.y + height) };
	}

	RECT RectMakePoint(POINT pt, float width, float height)
	{
		return {
			long(pt.x),
			long(pt.y),
			long(pt.x + width),
			long(pt.y + height) };
	}

	RECT RectMakePointCC(FPOINT pt, float width, float height)
	{
		return {
			long(pt.x - width / 2),
			long(pt.y - height / 2),
			long(pt.x + width / 2),
			long(pt.y + height / 2) };
	}

	RECT RectMakePointCC(POINT pt, float width, float height)
	{
		return {
			long(pt.x - width / 2),
			long(pt.y - height / 2),
			long(pt.x + width / 2),
			long(pt.y + height / 2) };
	}

	RECT RectMakePointCB(FPOINT pt, float width, float height)
	{
		return {
			long(pt.x - width / 2),
			long(pt.y - height),
			long(pt.x + width / 2),
			long(pt.y) };
	}

	RECT RectMakePointCB(POINT pt, float width, float height)
	{
		return {
			long(pt.x - width / 2),
			long(pt.y - height),
			long(pt.x + width / 2),
			long(pt.y) };
	}

	void RectangleMakeRect(HDC hdc, RECT rc , float x, float y)
	{
		Rectangle(hdc,
			rc.left + x,
			rc.top + y,
			rc.right + x,
			rc.bottom + y);
	}

	void EllipseMakeRect(HDC hdc, RECT rc)
	{
		Ellipse(hdc,
			rc.left,
			rc.top,
			rc.right,
			rc.bottom);
	}

	float getRectWidth(RECT rc)
	{
		return rc.right - rc.left;
	}

	float getRectHeight(RECT rc)
	{
		return rc.bottom - rc.top;
	}

	float getRectLeft(FPOINT pt, float width)
	{
		return pt.x - width / 2;
	}

	float getRectTop(FPOINT pt, float height)
	{
		return pt.y - height / 2;
	}

	float getRectLeft(POINT pt, float width)
	{
		return pt.x - width / 2;
	}

	float getRectTop(POINT pt, float height)
	{
		return pt.y - height / 2;
	}

	FPOINT getFPointLT(FPOINT pt, float width, float height)
	{
		return {
			pt.x - width / 2,
			pt.y - height / 2 };
	}

	void PtMoveAngleSpeed(FPOINT& pt, float angle, float speed)
	{
		pt.x += +cosf(angle) * speed;
		pt.y += -sinf(angle) * speed;
		return;
	}

	void XYMoveAngleSpeed(float& x, float& y, float angle, float speed)
	{
		x += +cosf(angle) * speed;
		y += -sinf(angle) * speed;
	}

	void PtMoveSpeed(FPOINT& pt, float speedX, float speedY)
	{
		pt.x += speedX;
		pt.y += speedY;
	}

	void XYMoveSpeed(float& x, float& y, float speedX, float speedY)
	{
		x += speedX;
		y += speedY;
	}

	void RectMoveSpeed(RECT& rc, float speedX, float speedY)
	{
		rc.left += speedX;
		rc.right += speedX;
		rc.top += speedY;
		rc.bottom += speedY;
	}

	void TTTextOut(HDC hdc, int x, int y, char* stri, float f, bool backGround)
	{
		int buffer = 3 + 4 + 1;	//" : ", "0.00", ""
		int unit = 10;
		while (f / (float)unit > 1)
		{
			buffer++;
			unit *= 10;
		}

		char* str = new char[buffer + strlen(stri)];
		sprintf(str, "%s : %.2f", stri, f);
		//SetTextColor(hdc, COLORREF)
		if (backGround) SetBkMode(hdc, TRANSPARENT);
		TextOut(hdc, x, y, str, strlen(str));
	}


	void TTTextOut(HDC hdc, int x, int y, char* stri, int d, bool backGround)
	{
		int buffer = 3 + 1 + 1;	//" : ", "0.00", ""
		int unit = 10;
		while (d / unit > 1)
		{
			buffer++;
			unit *= 10;
		}

		char* str = new char[buffer - 3 + strlen(stri)];
		sprintf(str, "%s : %d", stri, d);
		if (backGround) SetBkMode(hdc, TRANSPARENT);
		TextOut(hdc, x, y, str, strlen(str));
	}

	void TTTextOut(float f)
	{
		cout << f << endl;
	}

	BOOL ThisPixelIsMazen(HDC hdc, int x, int y)
	{
		COLORREF color = GetPixel(hdc, x, y);

		int r2 = GetRValue(color);
		int g2 = GetGValue(color);
		int b2 = GetBValue(color);

		if (r2 == 255 && g2 == 0 && b2 == 255)
		{
			return TRUE;
		}
		return FALSE;
	}

	RECT RectMakeSmall(RECT rc)
	{
		return {
			long(rc.left * SMALLX),
			long(rc.top * SMALLY),
			long(rc.right * SMALLX),
			long(rc.bottom * SMALLY) };
	}

	RECT RectMakeBig(RECT rc)
	{
		return {
			long(rc.left * BIGX),
			long(rc.top * BIGY),
			long(rc.right * BIGX),
			long(rc.bottom * BIGY) };
	}

	FPOINT PointMakeSmall(FPOINT pt)
	{
		return {
			pt.x * SMALLX,
			pt.y * SMALLY };
	}

	FPOINT PointMakeBig(FPOINT pt)
	{
		return {
			pt.x * BIGX,
			pt.y * BIGY };
	}

	int getbuffer10(float var)
	{
		int ret = 1;
		float unit = 10;
		float v = var;
		
		while (var > unit)
		{
			unit *= 10;
			++ret;
		}

		return ret;
	}

	int getbuffer01(float var)
	{
		int ret = 2;
		float v = var;

		while (v - (int)v > 0)
		{
			v *= 10;
			++ret;
		}

		return ret;
	}
}
