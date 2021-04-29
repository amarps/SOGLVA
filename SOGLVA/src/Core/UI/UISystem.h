#pragma once

#include "Panels/FPSCounter.h"
#include "Panels/Property.h"

/// \cond
#include <vector>
/// \endcond

/// this uiSystem class is for ui inside the opengl context.
/// ui system use nuklear library for rendering ui inside the opengl context.
/// this uisystem mean to be used in app for example for debugging or inapp ui
/// not inside level editor.
class UISystem
{
private:
	Rendering& rendering;

	/// <summary>
	/// contains every panel that implemented IUIDrawable interface.
	/// these panels will be called inside main loop by ui draw method
	/// from IUIDrawable interface.
	/// </summary>
	std::vector<IUIDrawable*> vUIPanels;

	/// <summary>
	/// contains current reference of glfw windows that will be used for nuklear context
	/// </summary>
	struct nk_glfw glfw = { 0 };

	/// <summary>
	/// nuklear context required by every nuklear call
	/// </summary>
	nk_context* context;

public:
	UISystem(Rendering& _rendering);

	~UISystem();

	/// <summary>
	/// create nuklear_glfw frame and draw every panels inside vUIPanels
	/// </summary>
	void DrawUiPanels();
};
