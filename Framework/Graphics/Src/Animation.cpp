#include "Precompiled.h"
#include "Animation.h"

using namespace SpringEngine;
using namespace SpringEngine::Graphics;

namespace
{
	float GetLerpTime(float startTime, float endTime, float time)
	{

	}
}

Transform Animation::GetTransform(float time) const
{
	Transform transform;
	transform.position = GetPosition(time);
	transform.rotation = GetRotation(time);
	transform.scale = GetScale(time);

	return transform;
}

float Animation::GetDuration() const
{
	//return mDuration;
}

Math::Vector3 Animation::GetPosition(float time) const
{
	for (uint32_t i = 0; i < mPositionKeys.size(); ++i)
	{
		if (time < mPositionKeys[i].time)
		{
			if (i > 0)
			{
				float t = GetLerpTime(mPositionKeys[i - 1].time, mPositionKeys[i].time)
			}
		}
		return mPositionKey
	}
}