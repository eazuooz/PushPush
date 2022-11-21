#pragma once
#include "GameObject.h"


//class Huose
//{
//
//};
//
//
//class Stone
//{
//
//};

class Player : public GameObject
{
public:
	Player();
	Player(Pos pos);
	~Player();

	virtual void Update(Map* map) override;
	virtual void Render() override;

	int GetStepCount() { return mStepCount; }

private:
	DIRECTION InputProcess();
	void OnCollisionBalls(Map* map, DIRECTION dir, Pos& prevPos);

private:
	int mStepCount;
};

