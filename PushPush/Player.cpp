#include "Player.h"
#include "Map.h"
#include "Ball.h"

Player::Player()
{
	mCh = L'★';
	mPos.y = 4;
	mPos.x = 4;
	mStepCount = 0;
}

Player::Player(Pos pos)
{
	mCh = L'★';
	mPos.y = pos.y;
	mPos.x = pos.x;
	mStepCount = 0;
}

Player::~Player()
{

}

void Player::Update(Map* map)
{
	Pos prevPos = mPos;
	DIRECTION dir = InputProcess();

	// 플레이어 벽 충돌 체크
	if (map->IsBarrier(mPos)) //참이면 벽이다
	{
		mPos = prevPos;
	}

	OnCollisionBalls(map, dir, prevPos);


	map->SetGameObjectInMap(mCh, mPos, prevPos);
}

void Player::Render()
{

}

DIRECTION Player::InputProcess()
{
	DIRECTION dir = DIRECTION::NONE;

	if (_kbhit())
	{        //키보드 입력 확인 (true / false)
		char input = _getch();

		dir = Move(input, mPos);
		mStepCount++;

		Beep(800, 100);
	}

	return dir;
}

void Player::OnCollisionBalls(Map* map, DIRECTION dir, Pos& prevPos)
{
	// 공 이랑 플레이어 충돌체크
	std::list<Ball*>& balls = Ball::GetBalls();
	for (std::list<Ball*>::iterator iter = balls.begin()
		; iter != balls.end()
		; iter++)
	{
		Pos ballPos = (*iter)->GetPos();
		Pos prevBallPos = ballPos;
		if (mPos == ballPos)
		{
			Move(dir, ballPos);

			// 공 벽충돌 체크
			if (map->GetPixel(ballPos) == L'▩'
				|| map->GetPixel(ballPos) == L'●')
			{
				ballPos = prevBallPos;

				// 플레이어도 움직이지 못하게 돌려주어야 한다.
				mPos = prevPos;
			}

			(*iter)->SetPos(ballPos);
			map->SetGameObjectInMap((*iter)->GetWChar_t(), ballPos, prevBallPos);
		}
	}
}
