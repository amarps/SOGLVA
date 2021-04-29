#pragma once
#include "Scene.h"
#include <map>
#include <string>

class SceneManager
{
private:
	Scene* currentScene;

public:
	std::map<std::string, Scene*> scenes;

	void ChangeCurrentScene(const char* name);

	Scene* GetCurrentScene();

	void CreateScene(std::string name = "Default Scene");

	void DeleteScene(const char* name);
};