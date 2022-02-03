#include "../../Common/d3dApp.h"
#include "../../Common/MathHelper.h"
#include "../../Common/UploadBuffer.h"
#include "../../Common/GeometryGenerator.h"
#include "World.h"

using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;


class Game : public D3DApp
{
public:
	Game(HINSTANCE hInstance);
	Game(const Game& rhs) = delete;
	Game& operator=(const Game& rhs) = delete;
	~Game();

	virtual bool Initialize()override;

private:

	virtual void Update(const GameTimer& gt)override;
	virtual void Render(const GameTimer& gt)override;


	void OnKeyDown(char key);
	void OnKeyUp(char key);
	void HandleInput(char key, bool keyDown);

	void UpdateStatistics();

	D3D12_VIEWPORT mWindow;
	World mWorld;

};