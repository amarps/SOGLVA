#include "Scene.h"
#include "ManagedObject/Components/BoxRigidBody.h"

#include <iostream>


Scene::Scene(std::string _name) :name(_name)
{
	auto cube = CreateManagedObject("cube");
	auto plane = new ManagedObject();

	cubeModel = new Model("resources/objects/primitive/cube.obj");
	cubeModel->shader = Shader("resources/shaders/object/Unlit.vs", "resources/shaders/object/unlit.fs", false);
	cubeModel->shader.setVec4("in_Tint", glm::vec4(0.5f, 0.5f, 1.0f, 1.0f));

	auto planeModel = new Model("resources/objects/primitive/plane/plane.obj");
	planeModel->shader = Shader("resources/shaders/object/Unlit.vs", "resources/shaders/default/gridPlane.fs", false);
	cubeModel->shader.setVec4("in_Tint", glm::vec4(1.0f, 0.5f, 1.0f, 1.0f));

	planeModel->transform.Scale(glm::vec3(1000.0f));
	cubeModel->transform.Translate(glm::vec3(0, 90, -10));

	plane->AddComponent(planeModel);
	cube->AddComponent(cubeModel);
	auto cubeRB = new BoxRigidBody(&cubeModel->transform, 1.0f);
	cube->AddComponent(cubeRB);

	// set worldPhysic
	btTransform plane_phys_trans;
	plane_phys_trans.setIdentity();
	plane_phys_trans.setOrigin(btVector3(0, 0, 0));
	btStaticPlaneShape* plane_phys_shape = new btStaticPlaneShape(btVector3(0, 1, 0), 0);
	btMotionState* motion = new btDefaultMotionState(plane_phys_trans);

	// set rigidbody
	btRigidBody::btRigidBodyConstructionInfo info(0.0f, motion, plane_phys_shape);
	btRigidBody* body = new btRigidBody(info);

	//RBspehere = worldPhysic.CreateSpehereRigidBody(3, cubeModel->transform.getPosition().x, cubeModel->transform.getPosition().y, cubeModel->transform.getPosition().z, 1);

	// setup world
	worldPhysic.m_rigidBodies.push_back(body);
	worldPhysic.m_rigidBodies.push_back(cubeRB->m_rigidBody);
	worldPhysic.m_world->addRigidBody(body);
	worldPhysic.m_world->addRigidBody(cubeRB->m_rigidBody);

	managedObjects["plane"] = plane;
	managedObjects["cube"] = cube;
}

Scene::~Scene()
{
	for (auto& mObj : managedObjects)
	{
		delete mObj.second;
	}
	managedObjects.clear();
}

void Scene::Update()
{
	worldPhysic.m_world->stepSimulation(1.0f / 60.0f);
	for (auto& mObj : managedObjects)
	{
		mObj.second->Update();
	}
}

ManagedObject* Scene::CreateManagedObject(std::string objName)
{
	auto tempObj = new ManagedObject(objName);

	this->managedObjects[objName] = tempObj;

	return tempObj;
}

ManagedObject* Scene::GetManagedObject(std::string objName)
{
	return this->managedObjects[objName];
}