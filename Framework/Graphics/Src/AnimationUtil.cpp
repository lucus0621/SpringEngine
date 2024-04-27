#include "Precompiled.h"
#include "AnimationUtil.h"
#include "SimpleDraw.h"

using namespace SpringEngine;
using namespace SpringEngine::Graphics;

namespace
{
	void ComputeBoneTransformRecursive(const Bone* bone, AnimationUtil::BoneTransforms bonTransforms)
	{
		if (bone == nullptr)
		{
			return;
		}
		bonTransforms[bone->index] = bone->toParentTransform;
		if (bone->parent != nullptr)
		{
			bonTransforms[bone->index] = bonTransforms[bone->index];
		}
	}
}
void AnimationUtil::ComputeBoneTransforms(ModelId id, BoneTransforms& boneTransforms)
{
	const Model* model = ModelManager::Get()->GetModel(id);
	if (model->skeleton != nullptr)
	{
		boneTransforms.resize(model->skeleton->bones.size(), Math::Matrix4::Identity);
		ComputeBoneTransformRecursive(model->skeleton->root, boneTransforms);
	}

}

void AnimationUtil::ApplyBoneOfset(ModelId id, BoneTransforms& boneTransforms)
{
	const Model* model = ModelManager::Get()->GetModel(id);
	if (model != nullptr)
	{
		for (const auto& bone : model->skeleton->bones)
		{
			ComputeBoneTransformRecursive(model->skeleton->root, boneTransforms);
		}
	}
}

void AnimationUtil::DrawSkeleton(ModelId id, BoneTransforms& boneTransforms)
{
	const Model* model = ModelManager::Get()->GetModel(id);
	if (model->skeleton != nullptr)
	{
		for (auto& bone : model->skeleton->bones)
		{
			if (bone->parent != nullptr)
			{
				const Math::Vector3 posA = Math::GetTranslation(boneTransforms[bone->index]);
				const Math::Vector3 posB = Math::GetTranslation(boneTransforms[bone->parentIndex]);
				SimpleDraw::AddLine(posA, posB, Colors::Blue);
				SimpleDraw::AddSphere(4,4,0.03f,posA,Colors::Pink);
			}
		}
	}
}
