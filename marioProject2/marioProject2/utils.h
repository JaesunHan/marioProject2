#pragma once

#define PI 3.141592654f
#define PI2 PI * 2

#define PI8		float(PI / 8.0f)
#define PI16	float(PI / 16.0f)
#define PI32	float(PI / 32.0f)
#define PI64	float(PI / 64.0f)
#define PI128	float(PI / 128.0f)

namespace HEPTA_UTIL
{
	float getDistance(float startX, float startY, float endX, float endY);

	float getAngle(float x1, float y1, float x2, float y2);



	//========================================================================== 테스트 렌더 

	// 테스트값 출력:        변수명      토글키값 변수값(flaot) 출력좌표x,y
	void testRender(HDC hdc, char* name, int key, float value, int x, int y);
	// 테스트값 출력:        변수명      토글키값 변수값(char)     출력좌표x,y
	void testRender(HDC hdc, char* name, int key, char* valueName, int x, int y);

}