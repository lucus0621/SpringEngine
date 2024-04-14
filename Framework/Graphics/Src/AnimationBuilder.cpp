#include"Precompiled.h"
#include"AnimationBuilder.h"

using namespace SpringEngine;
using namespace SpringEngine::Graphics;

namespace {
	template<class T>
	void PushKey(Keyframes<T>& keyframes, const T& value, float t, EaseType easeType = EaseType::Linear)
	{
		ASSERT(keyframes.empty() || keyframes.back().time <= t, "AnimationBuilder:")
		keyframes.emplace_back(value, t, easeType);
	}
}

AnimationBuilder& AnimationBuilder::AddPositionKey(const Math::Vector3& pos, float time, EaseType easeType)
{
	PushKey(mWorkingCopy.mPositionKeys, pot, time.easeType);
	mWorkingCopy.mDuration = Math::Max(mWorkingCopy.GetDuration,time)
	return *this;
}

AnimationBuilder& AnimationBuilder::AddRotation(const Math::Vector3& rot, float time, EaseType easeType)
{
	// TODO: insert return statement here
	return *this;
}

AnimationBuilder& AnimationBuilder::AddScaleKey(const Math::Vector3& scale, float time, EaseType easeType)
{
	// TODO: insert return statement here
	return *this;
}

Animation AnimationBuilder::Build()
{
	ASSERT(!mWorkingCopy.mPositionKeys.empty() ||
		!mWorkingCopy.mRotationKeys.empty() ||
		!mWorkingCopy.mScaleKeys.empty(),
		"AnimationBuilder: no Animation")
	return mWorkingCopy;

}
