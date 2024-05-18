#include "Precompiled.h"
#include "..\Inc\Particle.h"

using namespace SpringEngine;
using namespace SpringEngine::Math;
using namespace SpringEngine::Graphics;

void Particle::Initialize()
{
	mLifeTime = 0.0f;
	mCollisionShape.InitializeEmpty();
	mRigidBody.Initialize(mTransform, mCollisionShape, 0.1f);
}

void Particle::Terminate()
{
	mRigidBody.Terminate();
	mCollisionShape.Terminate();
}

void Particle::Activate(const ParticleActivateData& data)
{
	mData = data;
	mLifeTime = data.lifeTime;
	mRigidBody.SetPosition(data.position);
	mRigidBody.SetVelocity(data.velocity);
}

void Particle::Update(float deltaTime)
{
	mLifeTime -= deltaTime;
}

bool Particle::IsActive() const
{
	return mLifeTime > 0.0f;
}

void Particle::GetCurrentInfo(ParticleInfo& info) const
{
	if (mData.lifeTime > 0.0f)
	{
		float t = Clamp(mLifeTime / mData.lifeTime, 0.0f, 1.0f);
		info.currentColor = Lerp(mData.startColor, mData.endColor, t);
		info.currentScale = Lerp(mData.startScale, mData.endScale, t);
	}
}

const Transform& SpringEngine::Particle::GetTransform() const
{
	return mTransform;
}
