#pragma once
#include "gameNode.h"

//플레이어스테이터스
//대기, 점프, 이동, 달리기 등의 상태를 이넘으로 제어하기 위함
enum PLAYERSTATUS
{
	IDLE,
	JUMP,
	MOVE,
	RUN,
	ATTACK,
	SKILL,
	ENDSTATUS
};

//플레이어 타입
//마더플레이어는 BASIC 마리오 
//나머지는 자기 타입에 맞는 마리오를 넣으면 됩니다.
//FROG, HAMMER등등...
enum PLAYERTYPE
{
	BASIC,
	FROG,
	HAMMER,
	TANUKI,
	ENDTYPE
};

//플레이어가 바라보는 방향
enum PLAYERDIRECTION
{
	RIGHT,
	LEFT,
	ENDDIRECTION
};

//중력 상시적용을 위한 플레이어 위치 제어용
enum PLAYERWHERE
{
	ONLAND,
	OFFLAND,
	ENDWHERE
};

class player : public gameNode
{
protected:


	string _imageName;			//이미지 등록용
	RECT _playerRc;				//이미지 렉트용
	float _playerX;				//플레이어 x
	float _playerY;				//플레이어 y
	int _probeY;				//플레이어 y좌표 검출
	int _probeX;				//플레이어 x좌표 검출


	int _currentFrameX;			//프레임 관리용 x
	int _currentFrameY;			//프레임 관리용 y
	int _count;					//카운트용 변수
	int _countDead;				//죽음 카운트 변수
	float _speed;				//마리오 스피드
	float _angle;				//앵글
	float _gravity;				//중력... 그런데 중력을 플레이어에서 주는게 아니라 월드에서 줘야하는거 같은데..
	float _jumpPower;			//점프파워 


	///////////////이넘문 구분용///////////////

	PLAYERTYPE _typeNum;					//플레이어 타입 구분용
	PLAYERDIRECTION _directionNum;			//플레이어 방향 구분용
	PLAYERSTATUS _statusNum;				//플레이어 스테이터스 구분용
	PLAYERWHERE _whereNum;					//플레이어 위치 구분용

	///////////////bool값 정리들///////////////

	bool _isRight;				//오른쪽이니?
	bool _isIdle;				//대기상태니?
	bool _isJump;				//점프상태니?
	bool _isGravity;			//중력 받는 상태니?
	bool _isBasic;				//베이직 마리오 상태니? true면 베이직 마리오 init, 아니면 다른 마리오 init
	bool _RtBlock = false;
	bool _LtBlock = false;


public:

	player();
	~player();


	HRESULT init();
	HRESULT init(string imgKey, char* imgFileName, float x, float y, int totalWidth, int totalHeight, int frameNumX, int frameNumY, PLAYERTYPE playerType);
	void release();
	void update();
	void render();

	virtual void playerFrameControl();									//플레이어프레임 컨트롤
	virtual void move();												//움직이는 함수
	virtual void KeyControl();											//키컨트롤 함수
	void playerJump();													//점프함수
	void draw();														//랜더전에 따로 그려서 관리하는 함수
	virtual image* imageControl();										//이미지 변환제어 함수


	inline RECT getRect() { return _playerRc; }							//렉트 반환용 겟함수
	inline int getPlayerProbeY() { return _probeY; }					//충돌검출 Y좌표 겟함수
	inline int getPlayerProbeX() { return _probeX; }					//충돌검출 X좌표 겟함수
	inline float getJumpPower() { return _jumpPower; }					//점프파워 겟함수
	inline float getX() { return _playerX; }								//플레이어 겟X
	inline float getY() { return _playerY; }								//플레이어 겟Y
	inline int getPlayerWhere() { return _whereNum; }					//플레이어 겟where
	inline int getPlayerStatus() { return _statusNum; }					//플레이어 겟스테이터스	
	inline int getPlayerType() { return _typeNum; }						//플레이어 겟타입  베이직마리오니?
	inline int getPlayerDirection() { return _directionNum; }			//플레이어 겟다이렉션 오른쪽이니 왼쪽이니?




	void setProbeX(int probeX) { _probeX = probeX; }					//셋터 프로브X
	void setProbeY(int probeY) { _probeY = probeY; }					//셋터 프로브Y
	void setPlayerX(float playerX) { _playerX = playerX; }
	void setPlayerY(float playerY) { _playerY = playerY; }
	void setJumpPower(float jumpPower) { _jumpPower = jumpPower; }
	void setStatusNum(PLAYERSTATUS statusNum) { _statusNum = statusNum; }
	void setWhereNum(PLAYERWHERE whereNum) { _whereNum = whereNum; }

	
	inline void setPlayerRtBlock(bool block) { _RtBlock = block; }
	inline void setPlayerLtBlock(bool block) { _LtBlock = block; }
};
