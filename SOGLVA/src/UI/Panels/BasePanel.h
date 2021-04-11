#pragma once
#include "Rendering/RenderingSystem.h"

#include "common/NuklearImport.h"
#include "common/NuklearImport.h"
#include "common/standard.h"

class BasePanel
{
protected:
	nk_context*& context;
	RenderingSystem& rendering;
	std::string name;

public:
	BasePanel(nk_context*& _context, RenderingSystem& _rendering, const std::string& _name)
		:context(_context), rendering(_rendering), name(_name) { }
	
};