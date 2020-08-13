#include "stdafx.h"
#include "Homi.h"
#include "AllMap.h"

void Homi::Init()
{
	_name = "Homi";
	_tag = "ToolItem";
	_dmage = 1;
	_enumName = TOOLS::HOE;
}

void Homi::Action()
{
	_justSignal = true;
	_mapObject = MAPOBJECT::NONE;
	_mapTeeain = TERRAIN::END;
	//�� �μ���
	if (_map->GetTiles(_tileIndex[0]).object == MAPOBJECT::NONE &&
		_map->GetTiles(_tileIndex[0]).terrain == TERRAIN::DIRT)
	{
		_map->SetMapObject(_tileIndex[0], MAPOBJECT::HOETILE);
	}

}

void Homi::ReAction()
{
}
