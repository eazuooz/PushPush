#include "Map.h"
#include "Ball.h"
#include "Application.h"


Map::Map()
	: mDatas()
	, mSize({0, 0})
{
	memset(mGameObjects, 0, sizeof(GameObject*) * 128);
}

Map::Map(int x, int y)
	: mDatas()
	, mSize({ x, y })
{
	memset(mGameObjects, 0, sizeof(GameObject*) * 128);
	mDatas.resize(mSize.y);
	for (size_t i = 0; i < mSize.y; i++)
	{
		mDatas[i].resize(mSize.x);
	}

	for (size_t iy = 0; iy < mSize.y; iy++)
	{
		for (size_t ix = 0; ix < mSize.x; ix++)
		{
			mDatas[iy][ix].ch = L'ㅤ';
			mDatas[iy][ix].isLight = false;
		}
	}
}

Map::~Map()
{
	for (size_t i = 0; i < 128; i++)
	{
		if (mGameObjects[i] != nullptr)
		{
			delete mGameObjects[i];
			mGameObjects[i] = nullptr;
		}
	}

	Ball::Clear();
}

void Map::Initiailize(std::wstring& stageString)
{
	int idx = 0;
	for (size_t iY = 0; iY < mSize.y; iY++)
	{
		for (size_t iX = 0; iX < mSize.x; iX++)
		{
			mDatas[iY][iX].ch = stageString[idx++];
		}
	}
}

void Map::Update()
{
	std::list<Ball*> balls = Ball::GetBalls();
	for (auto ball : balls)
	{
		Pos ballPos = (*ball).GetPos();
		mDatas[ballPos.y][ballPos.x].isLight = false;
	}

	for (size_t i = 0; i < 128; i++)
	{
		if(mGameObjects[i] != nullptr)
			mGameObjects[i]->Update(this);
	}
}

void Map::Render(int x, int y)
{
	IntersectHouseToBall();


	for (int iY = 0; iY < mSize.y; iY++)
	{
		for (int iX = 0; iX < mSize.x; iX++)
		{
			//SET_COLOR(COLOR::DARK_SKY_BLUE);
			GOTO_XY( (short)(x + iX * 2), (short)(y + iY));

			if (mDatas[iY][iX].ch == L'★')
			{
				Pen pen(COLOR::GREEN, mDatas[iY][iX].ch);
			}

			if (mDatas[iY][iX].isLight == false)
			{
				Pen pen(mDatas[iY][iX].ch);
			}
			else
			{
				void* p = new int();
				srand((int)p);

				// 0 ~ 15
				COLOR col = (COLOR)((rand() % 15) + 1);
				Pen pen(col, mDatas[iY][iX].ch);

				delete p;
			}
			
			
		}
	}


}

void Map::IntersectHouseToBall()
{


	std::vector<GameObject*> houses;
	for (size_t i = 0; i < 128; i++)
	{
		GameObject* temp = nullptr;
		if (mGameObjects[i] != nullptr)
		{
			temp = mGameObjects[i];

			if (temp->GetWChar_t() == L'◆')
			{
				houses.push_back(temp);
			}
		}
	}

	
	int collisionCount = 0;
	std::list<Ball*> balls = Ball::GetBalls();
	for ( auto ball : balls)
	{
		for (GameObject* house : houses)
		{
			Pos ballPos = (*ball).GetPos();
			Pos housePos = house->GetPos();

			if (ballPos == housePos)
			{
				mDatas[housePos.y][housePos.x].isLight = true;
				collisionCount++;
			}
		}
	}

	if (collisionCount == Ball::GetBallsCount())
	{
		// 클리어 처리
		Application::GetInstance()->SetClearStage(true);
		
	}

	for (GameObject* house : houses)
	{


		Pos housePos = house->GetPos();
		mDatas[housePos.y][housePos.x].ch = L'◆';
	}



}

void Map::SetGameObjectInMap(int x, int y, wchar_t ch)
{
	mDatas[y][x].ch = ch;
}

void Map::SetGameObjectInMap(wchar_t ch, Vector2 pos, Vector2 prevPos)
{
	if (prevPos.y == -1 || prevPos.x == -1)
	{
		//
	}
	else
	{
		mDatas[prevPos.y][prevPos.x].ch = L'ㅤ';
		
	}
	mDatas[pos.y][pos.x].ch = ch;
}

void Map::AddGameObject(GameObject* gameObject)
{
	for (size_t i = 0; i < 128; i++)
	{
		if (mGameObjects[i] == nullptr)
		{
			mGameObjects[i] = gameObject;
			break;
		}
	}
}

bool Map::IsBarrier(Pos playerPos)
{


	wchar_t ch = mDatas[playerPos.y][playerPos.x].ch;

	if (ch == L'▩')
		return true;

	return false;
}

wchar_t Map::GetPixel(Pos pos)
{
	return mDatas[pos.y][pos.x].ch;
}

wchar_t Map::GetPixel(int y, int x)
{
	return mDatas[y][x].ch;
}


