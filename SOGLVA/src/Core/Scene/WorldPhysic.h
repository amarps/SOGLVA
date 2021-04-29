#pragma once

#include <bullet/btBulletDynamicsCommon.h>

/// \cond
#include <vector>
/// \endcond

class WorldPhysic
{
public:
	btDynamicsWorld* m_world;
	btDispatcher* m_dispatcher;
	btCollisionConfiguration* m_collisionConfig;
	btBroadphaseInterface* m_broadPhase;
	btConstraintSolver* m_solver;
	btVector3 m_gravitation;
	std::vector<btRigidBody*> m_rigidBodies;

	WorldPhysic();

	void Update();

	~WorldPhysic();

	btRigidBody* CreateSpehereRigidBody(float radius, float x, float y, float z, float _mass);
};