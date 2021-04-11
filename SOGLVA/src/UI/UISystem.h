#pragma once
#include "Rendering/RenderingSystem.h"

#include "common/NuklearImport.h"

#include "interfaces/IUIPanel.h"
#include "interfaces/ISystem.h"

#include "Panels/FPSCounter.h"
#include "Panels/Property.h"

class UISystem : ISystem
{
private:
	RenderingSystem& rendering;
	std::vector<std::unique_ptr<IUIPanel>> vIUIPanels;

	struct nk_glfw glfw = { 0 };
	int width = 0, height = 0;
	nk_context* context;

public:
	UISystem(RenderingSystem& _rendering) : rendering(_rendering) { }

	virtual void Init() override;

	virtual void Update() override;

	virtual void Exit() override;

};