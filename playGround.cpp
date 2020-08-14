#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화 함수
HRESULT playGround::init()
{
	gameNode::init(true);
	//POINT _CameraMouse = PointMake(_ptMouse.x + CAMERAMANAGER->getL(), _ptMouse.y + CAMERAMANAGER->getT()); 마우스 카메라 위치

	_Inv = new Inventory;
	_Inv->init();

	imginit();
	soundinit();

	SCENEMANAGER->addScene("타이틀화면", _TitleScene = new TitleScene);
	SCENEMANAGER->addScene("테스트", _Tset = new TestScene);
	SCENEMANAGER->addScene("맵툴", _MaptoolScene = new MapToolScene);
	SCENEMANAGER->addScene("LOADING", _LoadingScene = new LoadingScene);
	MapFarm* _farm;
	MapHome* _home;
	MapTest* _test;
	SCENEMANAGER->addScene("FARM", _farm = new MapFarm);
	SCENEMANAGER->addScene("HOME", _home = new MapHome);
	SCENEMANAGER->addScene("Test", _test = new MapTest);
	SCENEMANAGER->changeScene("Test");

	CAMERAMANAGER->setConfig(0, 0, WINSIZEX, WINSIZEY, 0, 0, 0, 0);
	return S_OK;
}

//메모리 해제
void playGround::release()
{
	OBJECTMANAGER->Release();
}

//연산
void playGround::update()
{
	gameNode::update();
	SCENEMANAGER->update();
	OBJECTMANAGER->Update();
	KEYANIMANAGER->update();

}

//그리기 전용
void playGround::render()
{	
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=================================================

	SCENEMANAGER->render();

	/////////////////////////////////
	TIMEMANAGER->render(getMemDC());
	//////////////////////////////////
	ZORDER->ZOrderRender();
	//=============================================
	_backBuffer->render(getHDC(), 0, 0);
}

void playGround::imginit()
{
	//타이틀화면 관련
	IMAGEMANAGER->addImage("TitleBackground", "image/타이틀/stardewPanorama(1600x900).bmp", 1600, 900, false, MAGENTA);
	IMAGEMANAGER->addImage("Title", "image/타이틀/타이틀(690x318).bmp", 690, 318, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("StartButton", "image/타이틀/Start(203x318).bmp", 203, 318, 1, 2, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("LoadButton", "image/타이틀/Load(203x318).bmp", 203, 318, 1, 2, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("ExitButton", "image/타이틀/Exit(203x318).bmp", 203, 318, 1, 2, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("MaptoolButton", "image/타이틀/maptool(203x318).bmp", 203, 318, 1, 2, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("TitleBrid", "image/타이틀/Brid(400x69).bmp", 400, 69, 4, 1, true, MAGENTA);

	//UI
	IMAGEMANAGER->addFrameImage("mouse", "image/마우스.bmp", 360, 60, 6, 1, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("SpingSunny", "image/봄_맑음20T(3800x162).bmp", 3800, 162, 19, 1, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("SpingRain", "image/봄_비20T(3800x162).bmp", 3800, 162, 19, 1, true, MAGENTA);
	IMAGEMANAGER->addImage("AlphaOnlyBlackWindow", "image/알파용검은화면.bmp", 1600, 900, false, MAGENTA);
	IMAGEMANAGER->addImage("ItemInformation", "image/일반아이템설명.bmp", 293, 258, true, MAGENTA);
	IMAGEMANAGER->addImage("RecoveryItemInformation", "image/회복아이템설명.bmp", 293, 258, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("Loading", "image/Loading(822x62).bmp", 822, 62,3,1, true, MAGENTA);
	IMAGEMANAGER->addImage("QuickSlot", "image/퀵슬롯.bmp", 800, 96, true, MAGENTA);
	IMAGEMANAGER->addImage("QuickSlotSelect", "image/퀵스선택.bmp", 64, 64, true, MAGENTA);
	IMAGEMANAGER->addImage("UpArrow", "image/위화살표.bmp", 40, 44, true, MAGENTA);
	IMAGEMANAGER->addImage("DownArrow", "image/아래화살표.bmp", 40, 44, true, MAGENTA);
	IMAGEMANAGER->addImage("ItemInfo", "image/일반아이템설명.bmp", 293, 258, true, MAGENTA);
	IMAGEMANAGER->addImage("RecoveryItemInfo", "image/회복아이템설명.bmp", 293, 258, true, MAGENTA);

	//환경
	IMAGEMANAGER->addImage("Environment_Clock", "Image/Environment/Environment_Clock.bmp", 284, 160, true, MAGENTA);

	//인벤토리
	IMAGEMANAGER->addImage("Inventory_BG", "Image/Inventory/Inventory_BG.bmp", 1600, 900, false, BLACK);
	IMAGEMANAGER->addImage("UI_Inventory_Day", "Image/Inventory/UI_Inventory_Day.bmp", 848, 648, true, MAGENTA);
	IMAGEMANAGER->addImage("UI_Inventory_Night", "Image/Inventory/UI_Inventory_Night.bmp", 848, 648, true, MAGENTA);
	IMAGEMANAGER->addImage("UI_Inventory_Craft_top", "Image/Inventory/UI_Inventory_Craft_top.bmp", 848, 648, true, MAGENTA);
	IMAGEMANAGER->addImage("UI_Inventory_Craft_bot", "Image/Inventory/UI_Inventory_Craft_bot.bmp", 848, 648, true, MAGENTA);
	IMAGEMANAGER->addImage("UI_Inventory_KeyInfo", "Image/Inventory/UI_Inventory_KeyInfo.bmp", 848, 648, true, MAGENTA);
	IMAGEMANAGER->addImage("UI_Inventory_Game_Close", "Image/Inventory/UI_Inventory_Game_Close.bmp", 848, 648, true, MAGENTA);
	IMAGEMANAGER->addImage("Inventory_Close", "Image/Inventory/Inventory_Close.bmp", 44, 44, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("UI_Inventory_Trashcan", "Image/Inventory/UI_Inventory_Trashcan.bmp", 184, 71, 4, 1, true, MAGENTA);

	//상점관련
	IMAGEMANAGER->addFrameImage("StoreOwnerPortrait", "image/상점/상점주인_초상화(420x630).bmp", 420, 630, 2, 3, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("StoreOwnerDot", "image/상점/상점주인_도트(200x600).bmp", 200, 600, 4, 6, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("StoreItme", "image/상점/상점물품.bmp", 1041, 210, 1, 2, true, MAGENTA);
	IMAGEMANAGER->addImage("StoreInfo", "image/상점/소개문.bmp", 250, 143, true, MAGENTA);
	IMAGEMANAGER->addImage("StoreWindow", "image/상점/상점창.bmp", 1085, 709, true, MAGENTA);
	IMAGEMANAGER->addImage("BeanSeed", "image/상점/beanSeed.bmp", 56, 56, true, MAGENTA);
	IMAGEMANAGER->addImage("CauliFlowerSeed", "image/상점/cauliFlowerSeed.bmp", 56, 56, true, MAGENTA);
	IMAGEMANAGER->addImage("PotatoSeed", "image/상점/potatoSeed.bmp", 56, 56, true, MAGENTA);
	IMAGEMANAGER->addImage("sugarRadishSeed", "image/상점/sugarRadishSeed.bmp", 56, 56, true, MAGENTA);
	IMAGEMANAGER->addImage("당근씨앗", "image/상점/당근씨앗.bmp", 56, 56, true, MAGENTA);

	//대화창관련
	IMAGEMANAGER->addImage("ChatBox", "image/대화창2.bmp", 900, 312, true, MAGENTA);
	IMAGEMANAGER->addImage("CloseButton", "image/닫기버튼.bmp", 44, 44, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("RightButton", "image/대화창_우측하단(330x33).bmp", 330, 33, 11, 1, true, WHITE);

	//테스트용 이미지입니다 무시하세요
	IMAGEMANAGER->addFrameImage("말랑카우", "image/말랑카우.bmp", 200, 300, 4, 6, true, MAGENTA);
	IMAGEMANAGER->addImage("초상화", "image/powerCow.bmp", 209, 200, true, MAGENTA);
	
	/////MapTool
	IMAGEMANAGER->addImage("CloseButton", "image/닫기버튼.bmp", 44, 44, true, MAGENTA);

	IMAGEMANAGER->addFrameImage("Terrain", "image/mapTool/Terrain.bmp", 0, 0, 512, 512, 512 / TILESIZE, 512 / TILESIZE, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("Terrain_InDoor", "image/mapTool/Indoor.bmp", 0, 0, 192, 512, 192 / TILESIZE, 512 / TILESIZE, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("Wall", "image/mapTool/Wall.bmp", 0, 0, 512, 448, 512 / TILESIZE, 448 / TILESIZE, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("HoeTile", "image/mapTool/HoeTile.bmp", 0, 0, 384, 384, 384 / TILESIZE, 384 / TILESIZE, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("Tree", "image/mapTool/Tree.bmp", 0, 0, 578, 384, 3, 1, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("House", "image/mapTool/House.bmp", 0, 0, 576, 576, 1, 1, true, MAGENTA);
	IMAGEMANAGER->addImage("Line", "image/mapTool/Line.bmp", 64, 64, true, MAGENTA);
	IMAGEMANAGER->addImage("Collision", "image/mapTool/Collision.bmp", 64, 64, true, MAGENTA);
	IMAGEMANAGER->addImage("Bed", "image/mapTool/Bed.bmp", 128, 192, true, MAGENTA);
	IMAGEMANAGER->addImage("Blanket", "image/mapTool/Blanket.bmp", 128, 192, true, MAGENTA);
	IMAGEMANAGER->addImage("Window", "image/mapTool/Window.bmp", 700, 900, true, MAGENTA);

	// Player
	IMAGEMANAGER->addFrameImage("player", "image/Player.bmp", 3000, 4500, 12, 18, true, RGB(255, 0, 255));

	//낚시
	IMAGEMANAGER->addImage("FishingGague", "image/낚시/낚시게이지.bmp", 12, 485, true, MAGENTA);
	IMAGEMANAGER->addImage("FishingMiniGame", "image/낚시/낚시미니게임.bmp", 128, 505, true, MAGENTA);
	IMAGEMANAGER->addImage("FishingBar", "image/낚시/낚시바.bmp", 34, 96, true, MAGENTA);
	IMAGEMANAGER->addImage("FishingStart", "image/낚시/낚시시작.bmp", 120, 49, true, MAGENTA);
	IMAGEMANAGER->addImage("FishingPower", "image/낚시/낚시최대파워던짐.bmp", 100, 36, true, MAGENTA);
	IMAGEMANAGER->addImage("FishingRareFish", "image/낚시/레어물고기.bmp", 28, 29, true, MAGENTA);
	IMAGEMANAGER->addImage("FishingFish", "image/낚시/물고기.bmp", 28, 28, true, MAGENTA);
	IMAGEMANAGER->addImage("FishingBox", "image/낚시/상자.bmp", 28, 34, true, MAGENTA);
	IMAGEMANAGER->addImage("FishingBack", "image/낚시/낚시말풍선.bmp", 200, 604, true, MAGENTA);

}

void playGround::soundinit()
{
	SOUNDMANAGER->addSound("TitleSound", "Sounds/opening.mp3", true, true);
	SOUNDMANAGER->addSound("maptool", "Sounds/maptool.mp3", true, true);
	SOUNDMANAGER->addSound("MenuSelect", "Sounds/menu_select.mp3", false, false);
}
