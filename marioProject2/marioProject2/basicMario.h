#pragma once
#include "player.h"
class basicMario :
	public player
{
public:
	basicMario();
	~basicMario();

	image* _imageName;			//�̹��� ��Ͽ�
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
	int _whereNum;							//�÷��̾� ��ġ ���п�

											///////////////bool�� ������///////////////

	bool _isRight;				//�������̴�?
	bool _isIdle;				//�����´�?
	bool _isJump;				//�������´�?
	bool _isGravity;			//�߷� �޴� ���´�?
	bool _isBasic;				//������ ������ ���´�? true�� ������ ������ init, �ƴϸ� �ٸ� ������ init


	virtual void move();												//�����̴� �Լ�
	//virtual void KeyControl();											//Ű��Ʈ�� �Լ�
	//virtual void imageControl();										//�̹��� ��Ȳ���� �ٲٴ� �Լ�

};

