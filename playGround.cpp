#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ �Լ�
HRESULT playGround::init()
{
	gameNode::init(true);
	imginit();

	_TitleScene = new TitleScene;
	_Tset = new TestScene;
	_MaptoolScene = new MapToolScene;

	SCENEMANAGER->addScene("Ÿ��Ʋȭ��", _TitleScene);
	SCENEMANAGER->addScene("�׽�Ʈ", _Tset);
	SCENEMANAGER->addScene("����", _MaptoolScene);


	SCENEMANAGER->changeScene("Ÿ��Ʋȭ��");

	return S_OK;
}

//�޸� ����
void playGround::release()
{
	
}

//����
void playGround::update()
{
	gameNode::update();
	

	SCENEMANAGER->update();
}

//�׸��� ����
void playGround::render()
{	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=================================================

	SCENEMANAGER->render();

	//=============================================
	_backBuffer->render(getHDC(), 0, 0);
}

void playGround::imginit()
{
	//UI 
	IMAGEMANAGER->addImage("TitleBackground", "image/Ÿ��Ʋ/stardewPanorama(1600x900).bmp", 1600, 900, false, MAGENTA);
	IMAGEMANAGER->addImage("Title", "image/Ÿ��Ʋ/Ÿ��Ʋ(690x318).bmp", 690, 318, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("StartButton", "image/Ÿ��Ʋ/Start(203x318).bmp", 203, 318, 1, 2, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("LoadButton", "image/Ÿ��Ʋ/Load(203x318).bmp", 203, 318, 1, 2, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("ExitButton", "image/Ÿ��Ʋ/Exit(203x318).bmp", 203, 318, 1, 2, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("MaptoolButton", "image/Ÿ��Ʋ/maptool(203x318).bmp", 203, 318, 1, 2, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("TitleBrid", "image/Ÿ��Ʋ/Brid(400x69).bmp", 400, 69, 4, 1, true, MAGENTA);
	
	IMAGEMANAGER->addImage("CloseButton", "image/�ݱ��ư.bmp", 44, 44, true, MAGENTA);
	IMAGEMANAGER->addImage("ChatWindow", "image/��ȭâ2.bmp", 900, 312, true, MAGENTA);
	IMAGEMANAGER->addImage("AlphaOnlyBlackWindow", "image/���Ŀ����ȭ��.bmp", 1600, 900, false, MAGENTA);
	IMAGEMANAGER->addFrameImage("mouse", "image/���콺.bmp", 180, 60, 3, 1, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("RightButton", "image/��ȭâ_�����ϴ�(330x33).bmp", 330, 33, 11, 1, true, WHITE);
	IMAGEMANAGER->addFrameImage("SpingSunny", "image/��_����20T(3800x162).bmp", 3800, 162, 19, 1, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("SpingRain", "image/��_��20T(3800x162).bmp", 3800, 162, 19, 1, true, MAGENTA);
	//IMAGEMANAGER->
	//IMAGEMANAGER->
	//IMAGEMANAGER->
	//IMAGEMANAGER->
	//IMAGEMANAGER->	
	//IMAGEMANAGER->		
	//IMAGEMANAGER->		
	//IMAGEMANAGER->
	//IMAGEMANAGER->
	//IMAGEMANAGER->
}

void playGround::soundinit()
{
	
}