#pragma once
#include <SpringEngine/Inc/SpringEngine.h>

class GameState : public SpringEngine::AppState
{
public:
	~GameState() = default;
	void Initialize()  override;
	void Terminate()  override;
	void Update(const float deltaTime) override;
	void Render() override;
	void DebugUI() override;

private:
	void UpdateCameraControl(float deltaTime);

	SpringEngine::Graphics::Camera mCamera;
	SpringEngine::Graphics::DirectionalLight mDirectionalLight;
	SpringEngine::Graphics::StandardEffect mStandardEffect;


	//ball info
	SpringEngine::Graphics::RenderObject mBall;
	SpringEngine::Physics::CollisionShape mBallShape;
	SpringEngine::Physics::RigidBody mBallRB;

	//ground info
	SpringEngine::Graphics::RenderObject mGround;
	SpringEngine::Physics::CollisionShape mGroundShape;
	SpringEngine::Physics::RigidBody mGroundRB;
};