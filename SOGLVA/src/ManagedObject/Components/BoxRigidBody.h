#pragma once
#include "BaseRigidbody.h"
#include "IComponent.h"
#include "iostream"

class BoxRigidBody : public BaseRigidbody, public IComponent
{
public:
	BoxRigidBody(Transform* mObjTrans, float mass = 0.0f)
	{
		_mObjTrans = mObjTrans;
		_mass = mass;
		CreateBody();
	}

	void CreateBody() override
	{
		_transform.setIdentity();

		auto mObjPos = _mObjTrans->getPosition();
		_transform.setOrigin(btVector3(mObjPos.x, mObjPos.y, mObjPos.z));

		btSphereShape* shape = new btSphereShape(1);
		btVector3 inertia(0, 0, 0);
		if (_mass != 0)
		{
			shape->calculateLocalInertia(_mass, inertia);
		}

		btMotionState* motion = new btDefaultMotionState(_transform);

		// set _rigidBody
		btRigidBody::btRigidBodyConstructionInfo info(_mass, motion, shape, inertia);
		btRigidBody* body = new btRigidBody(info);

		m_rigidBody = body;
	}

	virtual void Update() override
	{
		m_rigidBody->getMotionState()->getWorldTransform(_transform);
		_transform.getOpenGLMatrix(glm::value_ptr(_mObjTrans->transformMatrix));
	}

	// Inherited via IComponent
	virtual void Start() override;
	virtual void Exit() override;
};

