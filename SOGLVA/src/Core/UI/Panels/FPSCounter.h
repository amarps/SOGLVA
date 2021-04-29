#pragma once
#include "Core/UI/IUIDrawable.h"

#include "BasePanel.h"

class FPSCounter : public IUIDrawable, public BasePanel
{
private:
	std::string fpsText;

public:
	FPSCounter(nk_context*& _context, Rendering& _rendering, const std::string& _name)
		:BasePanel(_context, _rendering, _name) { }

	/// <summary>
	/// Draw Panel
	/// </summary>
	virtual void Draw() override;
};
