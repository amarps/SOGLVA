#pragma once
#include "Core/Rendering/Rendering.h"

#include "common/NuklearImport.h"

/// <summary>
/// abstract for every nuklear panel 
/// </summary>
class BasePanel
{
protected:
	nk_context*& context;
	Rendering& rendering;
	std::string name;

public:
	BasePanel(nk_context*& _context, Rendering& _rendering, const std::string& _name)
		:context(_context), rendering(_rendering), name(_name) { }

	~BasePanel()
	{
		nk_window_close(context, name.c_str());
	}
};