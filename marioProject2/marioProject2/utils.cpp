#include "stdafx.h"
#include "utils.h"

namespace HEPTA_UTIL
{

	float getDistance(float startX, float startY, float endX, float endY)
	{
		float x = endX - startX;
		float y = endY - startY;

		return sqrtf(x * x + y * y);
	}

	float getAngle(float x1, float y1, float x2, float y2)
	{
		float x = x2 - x1;
		float y = y2 - y1;

		float distance = sqrtf(x * x + y * y);

		float angle = acosf(x / distance);

		if (y2 > y1)
		{
			angle = 2 * PI - angle;
			if (angle >= 2 * PI) angle -= 2 * PI;
		}

		return angle;
	}

	//========================================================================================== �׽�Ʈ ����
	// �׽�Ʈ�� ���:        ������      ���Ű�� ������(flaot) �����ǥx,y
	void testRender(HDC hdc, char* name, int key, float value, int x, int y)
	{
		if (KEYMANAGER->isToggleKey(key))
		{
			char str[128];
			sprintf(str, "%s : %2.2f", name, value);
			TextOut(hdc, x, y, str, strlen(str));
		}
	}

	// �׽�Ʈ�� ���:        ������      ���Ű�� ������(char)     �����ǥx,y
	void testRender(HDC hdc, char* name, int key, char* valueName, int x, int y)
	{
		if (KEYMANAGER->isToggleKey(key))
		{
			char str[128];
			sprintf(str, "%s : %s", name, valueName);
			TextOut(hdc, x, y, str, strlen(str));

		}
	}
}