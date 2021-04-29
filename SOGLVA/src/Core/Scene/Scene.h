#pragma once
#include "ManagedObject/ManagedObject.h"
#include "WorldPhysic.h"
#include <map>

class Scene
{
public:
	std::string name;
	Model* cubeModel;
	WorldPhysic worldPhysic;

	/// <summary>
	/// managed object that will rendered inside this scene
	/// </summary>
	std::map<std::string, ManagedObject*> managedObjects;

	Scene(std::string _name);

	/// <summary>
	/// delete every managedObject inside managed objects data
	/// and clear the data container which is std::vector
	/// </summary>
	~Scene();

	/// <summary>
	/// call Update in every managedObject inside managed objects data
	/// </summary>
	void Update();

	/// Create and assign managed object to managedObjects map
	ManagedObject* CreateManagedObject(std::string objName);

	ManagedObject* GetManagedObject(std::string objName);

};

