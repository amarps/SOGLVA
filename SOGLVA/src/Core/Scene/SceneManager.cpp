#include "SceneManager.h"


void SceneManager::ChangeCurrentScene(const char* name)
{
	currentScene = scenes[name];
}

Scene* SceneManager::GetCurrentScene()
{
	return currentScene;
}

void SceneManager::CreateScene(std::string name)
{
	Scene* scene = new Scene(name);

	scenes[name] = scene;

	ChangeCurrentScene(name.c_str());
}

void SceneManager::DeleteScene(const char* name)
{
	Scene* scene = scenes[name];
};