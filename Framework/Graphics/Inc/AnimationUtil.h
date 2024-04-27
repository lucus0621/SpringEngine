#pragma once

#include "ModelManager.h";

namespace SpringEngine::Graphics::AnimationUtil
{
	using BoneTransforms = std::vector<Math::Matrix4>;

	void ComputeBoneTransforms(ModelId id, BoneTransforms& boneTransforms);
	void ApplyBoneOfset(ModelId id, BoneTransforms& boneTransforms);
	void DrawSkeleton(ModelId id, BoneTransforms& boneTransforms);
}