#pragma once
#include "Particle.h"

namespace SpringEngine
{
	struct ParticleSystemInfo
	{
		Math::Vector3 spawnPosition = Math::Vector3::Zero;
		Math::Vector3 spawnDirection = Math::Vector3::YAxis;
		float spawnDelay = 0.0f;
		float systemLifeTime = 0.0f;
		int minParticlePerEmit = 0;
		int maxParticlePerEmit = 0;
		float minTimeBetweenEmit = 0;
		float maxTimeBetweenEmit = 0;
		float minSpawnAngle = 0.0f;
		float maxSpawnAngle = 0.0f;
		float minSpeed = 0.0f;
		float maxSpeed = 0.0f;
		float minLifeTime = 0.0f;
		float maxLifeTime = 0.0f;
		Color minStartColor = Colors::White;
		Color maxStartColor = Colors::White;
		Color maxEndColor = Colors::White;
		Color maxEndColor = Colors::White;
		Math::Vector3 minStartScale = Math::Vector3::One;
		Math::Vector3 maxStartScale = Math::Vector3::One;
		Math::Vector3 minEndScale = Math::Vector3::One;
		Math::Vector3 maxEndScale = Math::Vector3::One;
		int maxParticle = 100;

		TextureId particleTextureId = 0;
	};

	class ParticleSystem
	{
	public:
		ParticleSystem() = default;
		~ParticleSystem() = default;

		void Initialize(const ParticleSystemInfo &info);
		void Terminate();
		void Update(float deltaTime);

		void DebugUI();

		template<class Effect>
		void Render(Effect& effect)
		{
			if (mLifeTime > 0.0f)
			{
				std::sort(mParicle.begin(), mParticle.end(), [](const Particle& a, const Particle& b)
					{
						return Math::MagnitudeSqr(b.GetTransform().position - mCamera->GetPosition() < MagnitudeSqr(a.GetTransform().position - mCamera->GetPosition())
							};
				ParticleInfo particleInfo;
				Graphic::Transform particleTransform;
				for (const Particle& particle : mParticles)
				{
					if (particle.IsActive())
					{
						particle.GetCurrentInfo(particleInfo);
					}
				}
			}
		}
	private:
		void SpawnParticles();
		void SpawnParticle();

		using Particle = std::vector<Particle>;
		Particle 
	};
}