#include "WorldPhysic.h"


WorldPhysic::WorldPhysic()
{

	m_collisionConfig = new btDefaultCollisionConfiguration();
	m_dispatcher = new btCollisionDispatcher(m_collisionConfig);
	m_broadPhase = new btDbvtBroadphase();
	m_solver = new btSequentialImpulseConstraintSolver();

	m_world = new btDiscreteDynamicsWorld(m_dispatcher, m_broadPhase, m_solver, m_collisionConfig);

	m_gravitation = btVector3(0.f, -10.f, -1.f);

	m_world->setGravity(m_gravitation);
}

void WorldPhysic::Update()
{
	m_world->stepSimulation(1.0f / 60.0f);
}

WorldPhysic::~WorldPhysic()
{
	delete m_world;
	delete m_dispatcher;
	delete m_collisionConfig;
	delete m_broadPhase;
	delete m_solver;
}

btRigidBody* WorldPhysic::CreateSpehereRigidBody(float radius, float x, float y, float z, float _mass)
{
	// set transform
	btTransform transform;
	transform.setIdentity();
	transform.setOrigin(btVector3(x, y, z));
	btSphereShape* shape = new btSphereShape(radius);
	btVector3 inertia(0, 0, 0);
	if (_mass != 0)
	{
		shape->calculateLocalInertia(_mass, inertia);
	}

	btMotionState* motion = new btDefaultMotionState(transform);

	// set rigidbody
	btRigidBody::btRigidBodyConstructionInfo info(_mass, motion, shape, inertia);
	btRigidBody* body = new btRigidBody(info);

	return body;
}
