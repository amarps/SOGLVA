#pragma once
#include "../SOGLVA_API.h"
#include <string>

namespace SOGLVA
{
	extern "C" void CreateScene(std::string sceneName="")
	{
		application.get()->sceneManager->CreateScene(sceneName);
	}

	extern "C" void ChangeCurrentScene(std::string sceneName = "")
	{
		application.get()->sceneManager->ChangeCurrentScene(sceneName.c_str());
	}

	extern "C" void DeleteScene(std::string sceneName = "")
	{
		application.get()->sceneManager->DeleteScene(sceneName.c_str());
	}
}
