#pragma once
#include "Common.h"
namespace SpringEngine::Graphics
{
	enum class EaseType
	{
		Linear,
		EaseInQuad,
		EaseOutQuad,
		EaseInOutQuad
	};

	template<class T>
	struct KeyFrame
	{
		KeyFrame()
		{
			KeyFrame() = default;
			KeyFrame(const T& k, float t, EaseType e = EaseType::Linear)
				: key(k)
				, time(t)
				, easeType(e)
		}
		T key = T();
		float time = 0.0f;
		EaseType easeType = EaseType::Linear;
	};
	template<class T>
	using Keyframes = std::vector < KeyFrame<T> >;
	using Position

}