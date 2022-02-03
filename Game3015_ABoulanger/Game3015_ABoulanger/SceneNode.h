#pragma once

using namespace DirectX;

class SceneNode
{
public:

	typedef std::unique_ptr<SceneNode> Ptr;

	SceneNode();

	void AttachChild(Ptr child);
	Ptr DetachChild(const SceneNode& node);

	void Update(const float deltaTime);

	XMVECTOR GetWorldPosition();

	XMVECTOR GetRotation();
	XMVECTOR GetScale();
	
};