#pragma once
#include <bullet/btBulletDynamicsCommon.h>
#include <glm/gtc/type_ptr.hpp>

#include "ManagedObject/Components/Transform.h"

class BaseRigidbody
{
protected:
	float _mass;
	btTransform _transform;
	Transform* _mObjTrans;

public:
	btRigidBody* m_rigidBody;

	virtual void CreateBody()
	{

	}
};
