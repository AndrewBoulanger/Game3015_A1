#pragma once
#include "../../Common/d3dApp.h"
#include "../../Common/MathHelper.h"

using namespace DirectX;

class World final
{
public:
	World();

	void update(const GameTimer& gt);
	void Draw(const GameTimer& gt);

	void LoadTextures();
	void BuildScene(D3D12_VIEWPORT window);
private:

	enum Layer
	{
		Background, Air, 
		
		LayerCount
	};

	D3D12_VIEWPORT mWindow;

	XMFLOAT3 mEyePos = { 0.0f, 0.0f, 0.0f };
	XMFLOAT4X4 mView = MathHelper::Identity4x4();
	XMFLOAT4X4 mProj = MathHelper::Identity4x4();


	XMFLOAT4X4 mWorldBounds;
	float mScrollSpeed;

};