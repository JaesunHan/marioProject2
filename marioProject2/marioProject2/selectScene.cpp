#include "stdafx.h"
#include "selectScene.h"


selectScene::selectScene()
{
}


selectScene::~selectScene()
{

}

HRESULT selectScene::init()
{
	_btnSceneChange = new button;
	//��ư �ʱ�ȭ(��ư�̹��� Ű��, X, Y��ǥ, ������X, Y ��ǥ, �ݹ������ �Լ��̸�)
	_btnSceneChange->init("��ư", WINSIZEX / 2, WINSIZEY - 100,
		PointMake(0, 1), PointMake(0, 0), cbSceneChange);

	_btnAngleDown = new button;
	_btnAngleDown->init("��ư", WINSIZEX / 2 - 200, WINSIZEY / 2,
		PointMake(0, 1), PointMake(0, 0), cbAngleDown);
	
	_btnAngleUp = new button;
	_btnAngleUp->init("��ư", WINSIZEX / 2 + 200, WINSIZEY / 2,
		PointMake(0, 1), PointMake(0, 0), cbAngleUp);

	_action = new action;
	_action->init();

	_actionImage = IMAGEMANAGER->findImage("bullet");
	_actionImage->setX(WINSIZEX / 2);
	_actionImage->setY(WINSIZEY / 2);

	//ȭ�� �߾ӿ��� 50,50 ���� 3�ʸ���
	_action->moveTo(_actionImage, 50, 50, 1.0f);

	return S_OK;
}

void selectScene::release()
{

}

void selectScene::update() 
{
	_btnSceneChange->update();
	_btnAngleDown->update();
	_btnAngleUp->update();

	_action->update();
}

void selectScene::render() 
{
	TextOut(getMemDC(), WINSIZEX / 2, 100, "����Ʈ ���̿�!", strlen("����Ʈ ���̿�!"));
	_btnSceneChange->render();
	_btnAngleDown->render();
	_btnAngleUp->render();

	_actionImage->render(getMemDC(), _actionImage->getX(), _actionImage->getY());
}

void selectScene::cbSceneChange()
{
	SCENEMANAGER->changeScene("��Ÿ��");
}

void selectScene::cbAngleUp()
{
	DATABASE->setElementDataAngle("battle", DATABASE->getElementData("battle")->angle += 0.2f);
}

void selectScene::cbAngleDown()
{
	DATABASE->setElementDataAngle("battle", DATABASE->getElementData("battle")->angle -= 0.2f);
}