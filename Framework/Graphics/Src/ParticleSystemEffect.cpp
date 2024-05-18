#include "Precompiled.h"
#include "ParticleSystemEffect.h"

#include "RenderObject.h"
#include "Camera.h"
#include "MeshBuffer.h"
#include "VertexTypes.h"

using namespace SpringEngine;
using namespace SpringEngine::Math;
using namespace SpringEngine::Graphics;

void ParticleEffect::Initialize()
{
	std::filesystem::path filePath = L"../../Assets/Shaders/Particle.fx";
	mVertexShader.Initialize<Vertex>(filePath);
	mPixelShader
	mParticleBuffer
	mSampler
	mBlendState
}

void ParticleEffect::Terminate()
{
	mVertexShader.Terminate();
	mPixelShader.Terminate();
	mParticleBuffer.Terminate();
	mSampler.Terminate();
	mBlendState.Terminate();
}

void ParticleEffect::Begin()
{
}

void ParticleEffect::End()
{
	mBlendState.ClearState();
}

void ParticleEffect::Render(const RenderObject& renderObject)
{
	Render(renderObject, Colors::White);
}

void ParticleEffect::Render(const RenderObject& renderObject, const Color& color)
{
	Matrix4 matView = mCamera->GetViewMatrix();
	Matrix4 matScale
}

void ParticleEffect::DebugUI()
{
}

void ParticleEffect::SetCamera(const Camera& camera)
{
	mCamera
}
