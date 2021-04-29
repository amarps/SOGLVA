#pragma once
#include "Core/Rendering/Rendering.h"
#include "Core/UI/UISystem.h"
#include "Core/Scene/SceneManager.h"
#include "Scripting/CoreCpp/RuntimeDllUpdate.h"

class Soglva
{
private:
	bool m_quit;
	RuntimeDLLUpdate* _dllUpdater;
	std::map<std::string, DllFunction> _entryPointMap;

public:
	std::unique_ptr<Rendering> rendering;
	std::unique_ptr<UISystem> ui;
	std::unique_ptr<SceneManager> sceneManager;

	Soglva();
	~Soglva();

	void Initialize();

	void Run();
	bool IsQuit();
	void Quit();
};
