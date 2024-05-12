#include "Precompiled.h"
#include "PhysicsWorld.h"
#include "PhysicsObject.h"

using namespace SpringEngine;
using namespace SpringEngine::Physics;

namespace 
{
	std::unique_ptr<PhysicsWorld> sPhysicsWorld;
}

void Physics::PhysicsWorld::StaticInitialize(const Settings& settings)
{
	ASSERT(sPhysicsWorld == nullptr, "physicsWorld is already initialized!");
	sPhysicsWorld = std::make_unique<PhysicsWorld>();
	sPhysicsWorld->Initialize(settings);
}

void Physics::PhysicsWorld::StaticTerminate()
{
	if (sPhysicsWorld != nullptr)
	{
		sPhysicsWorld->Terminate();
		sPhysicsWorld.reset();
	}
}

PhysicsWorld* SpringEngine::Physics::PhysicsWorld::Get()
{
	ASSERT(sPhysicsWorld != nullptr, "physicsWorld : is not initialized!");
	return sPhysicsWorld.get();
}

PhysicsWorld::~PhysicsWorld()
{
	ASSERT(mDynamicsWorld == nullptr, "PhysicsWorld: Terminate must be called!");
}

void PhysicsWorld::Initialize(const Settings& settings)
{
	mSettings = settings;
	mCollisionConfiguration = new btDefaultCollisionConfiguration();
	mDispatcher = new btCollisionDispatcher(mCollisionConfiguration);
	mInterface = new btDbvtBroadphase();
	msolver = new btSequentialImpulseConstraintSolver();
	mDynamicsWorld = new btDiscreteDynamicsWorld(mDispatcher, mInterface, msolver, mCollisionConfiguration);
	mDynamicsWorld->setGravity(ConvertTobtVector3(settings.gravity));
}

void PhysicsWorld::Terminate()
{
	SafeDelete(mDynamicsWorld);
	SafeDelete(msolver);
	SafeDelete(mInterface);
	SafeDelete(mDispatcher);
	SafeDelete(mCollisionConfiguration);
}

void PhysicsWorld::Update(float deltaTime)
{
	mDynamicsWorld->stepSimulation(deltaTime, mSettings.simulationSteps, mSettings.fixedTimeStep);
	
}

void PhysicsWorld::DebugUI()
{
	//later
}

void PhysicsWorld::Register(PhysicsObject* physicsObject)
{
	auto iter = std::find(mPhysicsObjects.begin(), mPhysicsObjects.end(), physicsObject);
	if (iter == mPhysicsObjects.end())
	{
		mPhysicsObjects.push_back(physicsObject);
		if (physicsObject->GetRigidBody() != nullptr)
		{
			mDynamicsWorld->addRigidBody(physicsObject->GetRigidBody());
		}
	}
}

void PhysicsWorld::Unregister(PhysicsObject* physicsObject)
{
	auto iter = std::find(mPhysicsObjects.begin(), mPhysicsObjects.end(), physicsObject);
	if (iter == mPhysicsObjects.end())
	{
		if (physicsObject->GetRigidBody() != nullptr)
		{
			mDynamicsWorld->removeRigidBody(physicsObject->GetRigidBody());
		}
		mPhysicsObjects.erase(iter);
	}
}
