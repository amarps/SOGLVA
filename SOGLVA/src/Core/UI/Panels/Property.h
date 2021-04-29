#pragma once
#include "Core/UI/IUIDrawable.h"

#include "BasePanel.h"

class Property : public IUIDrawable, public BasePanel
{
public:
	Property(nk_context*& _context, Rendering& _rendering, const std::string& _name)
		:BasePanel(_context, _rendering, _name) { }
			

	/// <summary>
	/// Draw Panel
	/// </summary>
	virtual void Draw() override;
};