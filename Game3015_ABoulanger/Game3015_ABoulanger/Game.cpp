#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance,
	PSTR cmdLine, int showCmd)
{
	// Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	try
	{
		Game game(hInstance);
		if (!game.Initialize())
			return 0;

		return game.Run();
	}
	catch (DxException& e)
	{
		MessageBox(nullptr, e.ToString().c_str(), L"HR Failed", MB_OK);
		return 0;
	}
}


Game::Game(HINSTANCE hInstance)
	: D3DApp(hInstance), mWorld(World())
{

}

Game::~Game()
{
	if (md3dDevice != nullptr)
		FlushCommandQueue();
}

bool Game::Initialize()
{
	if (!D3DApp::Initialize())
		return false;

	
	mWorld.LoadTextures();
	mWindow = D3DApp::mScreenViewport;
	D3DApp::mMainWndCaption = L"I can't think of a good name, but I do know how to change this caption";
	mWorld.BuildScene(mWindow);



	return true;
}


void Game::Update(const GameTimer& gt)
{
	mWorld.update(gt);
}

void Game::Render(const GameTimer& gt)
{
	mWorld.Draw(gt);
}


void Game::OnKeyDown(char key)
{
	HandleInput(key, true);
}

void Game::OnKeyUp(char key)
{
	HandleInput(key, false);
}

void Game::HandleInput(char key, bool keyDown)
{
	
}

void Game::UpdateStatistics()
{

}

