#pragma once

#include "PhysicsObject.h"
#include <Graphics/Inc/MeshTypes.h>

namespace SpringEngine::Physics
{
	class SoftBody final : public PhysicsObject
	{
	public:
		SoftBody() = default;
		~SoftBody() override;
		void Initialize(Graphics::Mesh& mesh, float mass, const std::vector<int>& fixedNodeInices);
		void Terminate();

	private:
		void Update() override;
		btSoftBody* GetSoftBody() ;

		btSoftBody* mSoftBody = nullptr;
		Graphics::Mesh* mMesh = nullptr;

	};
}