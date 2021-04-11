#pragma once
#include "interfaces/IUIPanel.h"

#include "BasePanel.h"

namespace UI
{
	namespace Panel
	{
		class Property : public IUIPanel, public BasePanel
		{
		public:
			Property(nk_context*& _context, RenderingSystem& _rendering, const std::string& _name)
				:BasePanel(_context, _rendering, _name) { }

			// Inherited via IUIPanel
			virtual void Setup() override;
			virtual void Draw() override;
		};
	}
}
