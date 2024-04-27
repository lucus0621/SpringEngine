#include "Precompiled.h"
#include "AnimationUtil.h"

using namespace SpringEngine;
using namespace SpringEngine::Graphics;
void AnimationUtil::ComputeBoneTransforms(ModelId id, BoneTransforms& boneTransforms)
{
}

void AnimationUtil::ApplyBoneOfset(ModelId id, BoneTransforms& boneTransforms)
{
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
				//get position of bones
				// get position of parent bone
				// simpldraw it 
			}
		}
	}
}
