#pragma once
#include "gameNode.h"

//�÷��̾�����ͽ�
//���, ����, �̵�, �޸��� ���� ���¸� �̳����� �����ϱ� ����
enum PLAYERSTATUS
{
	IDLE,
	JUMP,
	MOVE,
	RUN,
	ENDSTATUS
};

//�÷��̾� Ÿ��
//�����÷��̾�� BASIC ������ 
//�������� �ڱ� Ÿ�Կ� �´� �������� ������ �˴ϴ�.
//FROG, HAMMER���...
enum PLAYERTYPE
{
	BASIC,
	FROG,
	HAMMER,
	TANUKI,
	ENDTYPE
};

//�÷��̾ �ٶ󺸴� ����
enum PLAYERDIRECTION
{
	RIGHT,
	LEFT,
	ENDDIRECTION
};

//�߷� ��������� ���� �÷��̾� ��ġ �����
enum PLAYERWHERE
{
	ONLAND,
	OFFLAND,
	ENDWHERE
};

class player : public gameNode
{
protected:


	image * _imageName;			//�̹��� ��Ͽ�
	RECT _playerRc;				//�̹��� ��Ʈ��
	float _playerX;				//�÷��̾� x
	float _playerY;				//�÷��̾� y
	int _probeY;				//�÷��̾� y��ǥ ����
	int _probeX;				//�÷��̾� x��ǥ ����


	int _currentFrameX;			//������ ������ x
	int _currentFrameY;			//������ ������ y
	int _count;					//ī��Ʈ�� ����
	int _countDead;				//���� ī��Ʈ ����
	float _speed;				//������ ���ǵ�
	float _angle;				//�ޱ�
	float _gravity;				//�߷�... �׷��� �߷��� �÷��̾�� �ִ°� �ƴ϶� ���忡�� ����ϴ°� ������..
	float _jumpPower;			//�����Ŀ� 
								
								
	///////////////�̳ѹ� ���п�///////////////

	PLAYERTYPE _typeNum;					//�÷��̾� Ÿ�� ���п�
	PLAYERDIRECTION _directionNum;			//�÷��̾� ���� ���п�
	PLAYERSTATUS _statusNum;				//�÷��̾� �������ͽ� ���п�
	PLAYERWHERE _whereNum;					//�÷��̾� ��ġ ���п�

	///////////////bool�� ������///////////////

	bool _isRight;				//�������̴�?
	bool _isIdle;				//�����´�?
	bool _isJump;				//�������´�?
	bool _isGravity;			//�߷� �޴� ���´�?
	bool _isBasic;				//������ ������ ���´�? true�� ������ ������ init, �ƴϸ� �ٸ� ������ init

public:

	player();
	~player();


	HRESULT init();
	HRESULT init(string imgKey, char* imgFileName, float x, float y, int totalWidth, int totalHeight, int frameNumX, int frameNumY, PLAYERTYPE playerType);
	void release();
	void update();
	void render();

	virtual void playerFrameControl();									//�÷��̾������� ��Ʈ��
	virtual void move();												//�����̴� �Լ�
	virtual void KeyControl();											//Ű��Ʈ�� �Լ�
	void playerJump();													//�����Լ�
	void draw();														//�������� ���� �׷��� �����ϴ� �Լ�
	virtual void imageControl();										//�̹��� ��ȯ���� �Լ�


	inline RECT getRect() { return _playerRc; }							//��Ʈ ��ȯ�� ���Լ�
	inline int getPlayerProbeY() { return _probeY; }					//�浹���� Y��ǥ ���Լ�
	inline int getPlayerProbeX() { return _probeX; }					//�浹���� X��ǥ ���Լ�
	inline int getJumpPower() { return _jumpPower; }					//�����Ŀ� ���Լ�
	inline int getX() { return _playerX; }								//�÷��̾� ��X
	inline int getY() { return _playerY; }								//�÷��̾� ��Y
	inline int getPlayerWhere() { return _whereNum; }					//�÷��̾� ��where
	inline int getPlayerStatus() { return _statusNum; }					//�÷��̾� �ٽ������ͽ�	
	inline int getPlayerType() { return _typeNum; }						//�÷��̾� ��Ÿ��  ��������������?
	inline int getPlayerDirection() { return _directionNum; }			//�÷��̾� �ٴ��̷��� �������̴� �����̴�?

	
	void setProbeX(int probeX) { _probeX = probeX; }					//���� ���κ�X
	void setProbeY(int probeY) { _probeY = probeY; }					//���� ���κ�Y

};
