#pragma once
#include "gameNode.h"

struct tagTile
{
	TERRAIN terrain;
	MAPOBJECT object;
	RECT rc;
	int terrainframeX;
	int terrainframeY;
	int objectframeX;
	int objectframeY;
	bool collision;
};
struct tagSampleTile
{
	RECT rc;
	int terrainframeX;
	int terrainframeY;
};
struct tagCurrentTile
{
	TERRAIN terrain;
	MAPOBJECT object;
	RECT rc;
	int terrainframeX;
	int terrainframeY;
};
class MapToolScene : public gameNode
{
private:
	image* _Mouse;
	CRTSELECT _crtSelect;

	tagSampleTile _sampleTile[15 * 5];
	tagCurrentTile _currentTile;

	Vector2 _Line;
	Vector2 _Ex;   // ���콺 �巡�� ���� ��ǥ

	RECT _draw;
	RECT _sampleArea;
	RECT _terrainBtn;
	RECT _treeBtn;
	RECT _buildingBtn;
	RECT _enemyBtn;
	RECT _collisionBtn;
	RECT _saveBtn;
	RECT _loadBtn;
	RECT _eraserBtn;
	RECT _exitBtn;

	int _horizontal;	//����
	int _vertical;		//����

	bool _drag;
	bool _isLeftClick;

	vector<tagTile>				_vtiles;
	vector<tagTile>::iterator	_vitiles;

public:
	MapToolScene();
	~MapToolScene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void SetUp();
	void SetSample(string img);

	void SetMap_L();
	void SetMap_R();
	void Save();
	void Load();

	TERRAIN TerrainSelect(int frameX, int frameY);
	MAPOBJECT ObjectSelect(int frameX, int frameY);

	vector<tagTile> GetTile() { return _vtiles; }
	int GetVertical() { return _vertical; }
	int GetHorizontal() { return _horizontal; }

	void SetTileTerrain(int x, int y, TERRAIN terrain);
};