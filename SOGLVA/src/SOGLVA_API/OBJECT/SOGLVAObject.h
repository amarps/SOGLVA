#pragma once
#include "../SOGLVA_API.h"

namespace SOGLVA
{
	// create managed object and assign it to the current scene
	extern "C" ManagedObject* CreateManagedObject(std::string objectName)
	{
		auto curScene = application.get()->sceneManager->GetCurrentScene();
		auto resObject = curScene->CreateManagedObject(objectName);
		return resObject;
	}

	extern "C" ManagedObject * GetManagedObject(std::string objectName)
	{
		auto curScene = application.get()->sceneManager->GetCurrentScene();
		auto resObject = curScene->GetManagedObject(objectName);
		return resObject;
	}

	extern "C" void AddComponent(ManagedObject* mObject, IComponent * component)
	{
		mObject->AddComponent(component);
	}

	extern "C" void GetComponent(ManagedObject * mObject, IComponent * component)
	{
		mObject->GetComponent(component);
	}

}
