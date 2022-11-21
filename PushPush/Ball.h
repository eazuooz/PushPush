#pragma once
#include "Common.h"
#include "GameObject.h"

class Ball : public GameObject
{
public:
	static std::list<Ball*>& GetBalls() { return mBalls; }
	static int GetBallsCount() { return mBallCount; }
	static void Clear();

	Ball();
	Ball(Pos pos);
	~Ball();
	
	void Initialize(Pos pos = Pos(-1, -1));
	virtual void Update(Map* map) override;
	virtual void Render() override;



private:
	static int mBallCount;
	static std::list<Ball*> mBalls;
};

