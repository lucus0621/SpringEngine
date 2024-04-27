#pragma once

#include "MeshBuffer.h"
#include "Transform.h"
#include "TextureManager.h"
//#include "Material.h"
#include "ModelManager.h"
namespace SpringEngine::Graphics
{
	struct Model;

	class RenderObject
	{
	public:
		void Terminate();
		Transform transform;
		MeshBuffer meshBuffer;

		ModelId modelId;
		Material material;
		TextureId diffuseMapId;
		TextureId normalMapId;
		TextureId specMapId;
		TextureId bumpMapId;

		const Skeleton* skeleton = nullptr;
	};

	using RenderGroup = std::vector<RenderObject>;
	[[nodiscard]] RenderGroup CreateRenderGroup(ModelId id);
	[[nodiscard]] RenderGroup CreateRenderGroup(const Model& model);
	void CleanupRenderGroup(RenderGroup& renderGroup);
	void SetRenderGroupPosition(RenderGroup& renderGroup, const Math::Vector3& position);

	template<class Effect>
	void DrawRenderGroup(Effect& effect, const RenderGroup& renderGroup)
	{
		for (const RenderObject& renderObject : renderGroup)
		{
			effect.Render(renderObject);
		}
	}
}