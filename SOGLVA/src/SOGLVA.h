#pragma once
#include "Rendering/RenderingSystem.h"
#include "UI/UISystem.h"
#include "common/standard.h"

class SOGLVA
{
private:
	std::unique_ptr<RenderingSystem> rendering;
	std::unique_ptr<UISystem> ui;

public:
	SOGLVA() = default;

	bool Init();
};