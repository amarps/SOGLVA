#pragma once
#include "interfaces/IUIPanel.h"

#include "BasePanel.h"

namespace UI
{
	namespace Panel
	{

		class FPSCounter : public IUIPanel, public BasePanel
		{
		private:
			std::string fpsText;

		public:
			FPSCounter(nk_context*& _context, RenderingSystem& _rendering, const std::string& _name)
				:BasePanel(_context, _rendering, _name) { }

			virtual void Setup() override;
			virtual void Draw() override;
		};

	}
}
