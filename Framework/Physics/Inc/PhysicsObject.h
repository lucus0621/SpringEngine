#pragma once

class btRigidBody;

namespace SpringEngine::Physics
{
	class PhysicsObject
	{
	public:
			PhysicsObject() = default;
			virtual ~PhysicsObject() = default;
	protected:
		friend class PhysicsWorld;

		virtual void Update() = 0;
		virtual btRigidBody* GetRigidBody() { return nullptr; }
	};
}