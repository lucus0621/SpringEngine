#include "Precompiled.h"
#include "Animator.h"

using namespace SpringEngine;


void Animator::Initialize(ModelId id)
{

}

void Animator::PlayAnimation(int clipIndex, bool looping)
{

}

void Animator::Update(float deltaTime)
{
	if (mClipIndex < 0)
	{
		return;
	}
	const Model* model = ModelManager::Get()->GetModel(mModelId);
	const AnimationClip& animClip = model->animationClips[mClipIndex];
	mAnimationTick += animClip.tickPerSecond * deltatime;
}

bool Animator::IsFinished() const
{
	if (mIsLooping || mClipIndex < 0)
	{
		return false;
	}
	const Model* model = ModelManager::Get()->GetModel(mModelId);
	const AnimationClip& animClip = model->animationClips[mClipIndex];
	return mAnimationTick >= animClip.tickDuration;
}

size_t SpringEngine::Graphics::Animator::GetAnimationCount() const
{
	const Model* model = ModelManager::Get()->GetModel(mModelId);
	return model->animationClips.size();
}

Math::Matrix4 SpringEngine::Graphics::Animator::GetToParentTransform(const Bone* bone) const
{
	if (mClipIndex < 0)
	{
		return bone->toParentTransform;
	}
	const Model* model = ModelManager::Get()->GetModel(mModelId);
	const AnimationClip& animClip = model->animationClips[mClipIndex];
	const AnimationClip8 animation = animClip.boneAnimation[bone->index].get();
	if (animation == nullptr)
	{
		return bone->toParentTransform;
	}
	Transform transform = animation->GetTransform(mAnimationTick);
	return transform.GetMatrix4();
}
