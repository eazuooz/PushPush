#pragma once
#include "Common.h"
#include "GameObject.h"
#include "Player.h"
//출력용 가운데 좌표
#define SIZE_MAP_Y 30
#define SIZE_MAP_X 24

struct Pixel
{
	wchar_t ch;
	bool isLight;
};


class Scene;
class Map 
{
public:
	Map();
	Map(int x, int y);
	~Map();

	void Initiailize(std::wstring& stageString);
	void Update();
	void Render(int x, int y);
	void IntersectHouseToBall();
	void SetGameObjectInMap(int x, int y, wchar_t ch);
	void SetGameObjectInMap(wchar_t ch, Vector2 pos, Vector2 prevPos = Vector2(-1,-1));
	void SetPlayer(Player* player) { mPlayer = player; }
	Player* GetPlayer() { return mPlayer; }

	void AddGameObject(GameObject* gameObject);
	bool IsBarrier(Pos pos);
	wchar_t GetPixel(Pos pos);
	wchar_t GetPixel(int y, int x);

private:
	//wchar_t** mDatas;
	std::vector<std::vector<Pixel>> mDatas;

	Size mSize;

	GameObject* mGameObjects[128];
	Player* mPlayer;
	Scene* mPlayScene;
};

