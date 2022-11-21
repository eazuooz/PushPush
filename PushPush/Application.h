#pragma once
#include "Common.h"
#include "Scene.h"


enum SCENETYPE
{
	TITLE,
	PLAY,
	//CLER,
	//GAMEOVER,
	END,
};


//Application* GetInstance2() 
//{
//	return nullptr;
//}

// ╫л╠шео фпео
class Application
{
public:
	static Application* GetInstance()
	{
		if (mInstance == nullptr)
		{
			mInstance = new Application();
		}

		return mInstance;
	}

public:
	bool Initiailize();
	void Update();
	void Rendering();
	void Destroy();

	bool GetIsRunning() { return mbRunning; }
	void SetIsRunning(bool running) { mbRunning = running; }
	void SetPlaySceneNumber(int number) { mPlaySceneNumber = number; }
	bool GetIsClear() { return mClearStage; }
	void SetClearStage(bool value) { mClearStage = value; }
	void InitializeNextStage();

private:
	Application();
	~Application();

	void clear();

private:
	static Application* mInstance;
	bool mbRunning;
	Scene* mScenes[SCENETYPE::END];
	int mPlaySceneNumber;
	bool mClearStage;
};


