#include "Application.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "Sound.h"

Application* Application::mInstance = nullptr;

void Application::InitializeNextStage()
{

}

Application::Application()
	: mbRunning(true)
	, mPlaySceneNumber((int)SCENETYPE::TITLE)
	, mClearStage(false)
{
	clear();
}

Application::~Application()
{

}

void Application::clear()
{
	for (int i = 0; i < SCENETYPE::END; i++)
	{
		mScenes[i] = nullptr;
	}
}

bool Application::Initiailize()
{
	Sound::Play(true);

	mScenes[SCENETYPE::TITLE] = new TitleScene();
	mScenes[SCENETYPE::PLAY] = new PlayScene();

	for (int i = 0; i < SCENETYPE::END; i++)
	{
		mScenes[i]->Initiailize();
	}
	
	return true;
}

void Application::Update()
{
	mScenes[mPlaySceneNumber]->Update();


}

void Application::Rendering()
{
	//system("cls");
	mScenes[mPlaySceneNumber]->Render();
	Sleep(200);
	

	//
	if (mClearStage)
	{
		mScenes[mPlaySceneNumber]->Destroy();
		mScenes[mPlaySceneNumber]->Initiailize();
		


		mClearStage = false;
	}
}

void Application::Destroy()
{
	for (int i = 0; i < SCENETYPE::END; i++)
	{
		mScenes[i]->Destroy();
	}

	for (int i = 0; i < SCENETYPE::END; i++)
	{
		if(mScenes[i] != nullptr)
			delete mScenes[i];
	}
}

