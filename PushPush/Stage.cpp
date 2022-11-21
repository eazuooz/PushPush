#include "Stage.h"
#include "Player.h"
#include "Ball.h"
#include "House.h"
#include <string>

Stage::Stage()
	: mStageNumber(1)
{

}

Stage::~Stage()
{

}

Map* Stage::Load(int stageNumber)
{
	FILE* fp = nullptr;
	mStageNumber = stageNumber;
	std::string path = "..\\Stages\\Stage" + std::to_string(mStageNumber) + ".txt";

	errno_t error = fopen_s(&fp, path.c_str(), "rt,ccs=UTF-8");
	if (error != 0)
	{
		std::wcout << L"스테이지 파일이 없습니다.\n";
		std::wcout << L"파일 경로를 확인해주세요.\n";
		exit(0);
	}
	wchar_t buff[64] = L"";
	std::wstring x = fgetws(buff, 63, fp);
	std::wstring y = fgetws(buff, 63, fp);

	int mapX = std::stoi(x);
	int mapY = std::stoi(y);
	mMap = new Map(mapX, mapY);

	for (size_t y = 0; y < mapY; y++)
	{
		fgetws(buff, 63, fp);
		for (size_t x = 0; x < mapX; x++)
		{
			if (buff[x] == L'ㅤ' || buff[x] == L'▩')
				mMap->SetGameObjectInMap(x, y, buff[x]);
			else
				CreateGameObject(buff[x], x, y);
		}
	}

	fclose(fp);
	return mMap;
}

void Stage::CreateGameObject(wchar_t type, int x, int y)
{
	switch (type)
	{
	case L'★':
	{
		Player* player = new Player(Pos(x,y));
		mMap->AddGameObject(dynamic_cast<GameObject*>(player));
		mMap->SetPlayer(player);
	}
	break;

	case L'●':
	{
		Ball* ball = new Ball(Pos(x, y));
		mMap->AddGameObject(dynamic_cast<GameObject*>(ball));
	}
	break;

	case L'◆':
	{
		House* house = new House(Pos(x, y));
		mMap->AddGameObject(dynamic_cast<GameObject*>(house));
	}
	break;

	default:
		break;
	}

}


