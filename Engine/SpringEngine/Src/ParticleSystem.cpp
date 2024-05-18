#include "Precompiled.h"
#include "ParticleSystem.h"

using namespace SpringEngine;
using namespace SpringEngine::Math;

void ParticleSystem::Initialize(const ParticleSystemInfo& info)
{
	MeshPX particleMesh = MeshBuilder::CreateSpriteQuad(0.1f, 0.1f);
	mRenderObject.meshBuffer.Initialize(particleMesh);
	mRenderObject.diffuseMapId = info.particleTextureId;
}

void ParticleSystem::Terminate()
{
	mRenderObject.Terminate();
	for (Particle& p : mParticles)
	{
		p.Terminate();
	}
}

void ParticleSystem::Update(float deltaTime)
{
	if (mLifeTime > 0.0f)
	{
		mLifeTime -= deltaTime;
	}
}

void ParticleSystem::DebugUI()
{
	if (ImGui::CollapsingHeader("PaticleSystem", ImGuiTreeNodeFlags_DefaultOpen))
	{
		ImGui::DragFloat3("SpawnPosition", &mInfo.spawnPosition.x);
		if (ImGui::DragFloat3("SpawnDirection", &mInfo.spawnDirection.x))
		{
			mInfo.spawnDirection = Normalize(mInfo.spawnDirection);
		}

		ImGui::DragInt("MinPerEmit", &mInfo.minParticlePerEmit);
		ImGui::DragInt("MaxPerEmit", &mInfo.maxParticlePerEmit, 1, mInfo.minParticlePerEmit + );
		ImGui::DragFloat("MinTime", &mInfo.minTimeBetweenEmit, 0.1f);
		ImGui::DragFloat("MaxTime", &mInfo.minTimeBetweenEmit, 0.1f), mInfo.maxTimeBetweenEmit);
		ImGui::DragFloat("MinAngle", &mInfo);
		ImGui::DragFloat("MaxAngle", &mInfo);
		ImGui::DragFloat("MinSpeed", &mInfo);
		ImGui::DragFloat("MaxSpeed", &mInfo);
		ImGui::DragFloat("MinLifeTime", &mInfo);
		ImGui::DragFloat("MaxLifeTime", &mInfo);
		ImGui::DragFloat("MinStartColor", &mInfo);
		ImGui::DragFloat("MaxStartColor", &mInfo);
		ImGui::DragFloat("MinEndColor", &mInfo);
		ImGui::DragFloat("MaxEndColor", &mInfo);
		ImGui::DragFloat("MinStartScale", &mInfo);
		ImGui::DragFloat("MaxStartScale", &mInfo);
		ImGui::DragFloat("MinEndScale", &mInfo);
		ImGui::DragFloat("MaxEndScale", &mInfo);
	}
}

void ParticleSystem::SpawnParticles()
{
	int numParticles = mInfo.minParticlePerEmit +
		(rand() % (mInfo.maxParticlePerEmit - mInfo.minParticlePerEmit));
	for (int i = 0; i < numParticles; ++i)
	{
		SpawnParticle();
	}
	float randF = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	mNextSpawnTime = mInfo.minTimeBetweenEmit+
		(randF * (mInfo.maxTimeBetweenEmit - mInfo.minTimeBetweenEmit));
}

void ParticleSystem::SpawnParticle()
{
	Particle& p = mParticle[mNextAvailableParticleIndex];
	mNextAvailableParticleIndex = (mNextAvailableParticleIndex + 1) % mPartcles.size();

	Vector3 spawnDirection = mInfo.spawnDirection;
	if (mInfo.maxSpawnAngle > 0.0f)
	{
		float randF = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		float randAngle = mInfo.minSpawnAngle +
			(randF * (mInfo.maxSpawnAngle - mInfo.minSpawnAngle));

		Vector3 rotAxisA, rotAxisB;
		if (abs(Dot(mInfo.spawnDirection, Vector3::YAxis)) > 0.99f)
		{
			rotAxisA = Normalize(Cross(mInfo.spawnDirection, Vector3::XAxis));
			rotAxisB = Normalize(Cross(mInfo.spawnDirection, rotAxisA));
		}
		else
		{
			rotAxisA = Normalize(Cross(mInfo.spawnDirection, Vector3::YAxis));
			rotAxisB = Normalize(Cross(mInfo.spawnDirection, rotAxisA));
		}

		Matrix4 matRotA = Matrix4::RotationAxis(rotAxisA, randAngle);
		Matrix4 matRotB = Matrix4::RotationAxis(rotAxisB, randAngle);
		spawnDirection = TransformNormal(mInfo.spawnDirection, matRotA * matRotB);
	}
	float randF = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	float speed = mInfo.minSpeed + (randF * (mInfo.maxSpeed - mInfo.minSpeed));

	ParticleActivateData data;
	data.velocity = spawnDirection * speed;
	data.position = mInfo.spawnPosition;

	float randF = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	data.lifeTime = mInfo.minLifeTime + (randF * (mInfo.maxLifeTime - mInfo.minLifeTime));

	float randF = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	data.startColor = Lerp(mInfo.minStartColor, mInfoStartColor, t);

	t = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	data.endColor = Lerp(mInfo.minStartColor, mInfoStartColor, t);

	t = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	data.startScale = Lerp(mInfo.minStartColor, mInfoStartColor, t);

	t = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	data.endScale = Lerp(mInfo.minStartColor, mInfoStartColor, t);
}
