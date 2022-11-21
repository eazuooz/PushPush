#pragma once
#include "Common.h"
#include "Map.h"

class Stage
{
public:
	Stage();
	~Stage();

	Map* Load(int stageNumber = 1);
	void CreateGameObject(wchar_t type, int x, int y);

	UINT GetStageNumber() { return mStageNumber; }

	

private:
	Map* mMap;
	UINT mStageNumber;
};

