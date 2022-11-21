#include "Ball.h"
#include "Map.h"
#include "Application.h"

int Ball::mBallCount = 0;
std::list<Ball*> Ball::mBalls;

void Ball::Clear()
{
	mBalls.clear();
	mBallCount = 0;
}

Ball::Ball()
{
	Initialize();
}

Ball::Ball(Pos pos)
{
	Initialize(pos);

}

Ball::~Ball()
{

}

void Ball::Initialize(Pos pos)
{


	mPos = pos;
	mCh = L'¡Ü';

	mBallCount++;
	mBalls.push_back(this);
}

void Ball::Update(Map* map)
{
	Pos prevPos = mPos;
	map->SetGameObjectInMap(mCh, mPos, prevPos);


}

void Ball::Render()
{

}
