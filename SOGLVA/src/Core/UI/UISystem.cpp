#include "UISystem.h"


UISystem::UISystem(Rendering& _rendering) : rendering(_rendering)
{
	context = nk_glfw3_init(&glfw, rendering.window, NK_GLFW3_INSTALL_CALLBACKS);

	{
		nk_font_atlas* atlas;
		nk_glfw3_font_stash_begin(&glfw, &atlas);
		nk_glfw3_font_stash_end(&glfw);
	}

	set_style(context, THEME_WHITE);

	vUIPanels.push_back(new FPSCounter(context, rendering, "FPS Counter"));
	vUIPanels.push_back(new Property(context, rendering, "Property"));
}

UISystem::~UISystem()
{
	for (auto& iPanel : vUIPanels)
	{
		delete iPanel;
	}

	nk_free(context);
}

void UISystem::DrawUiPanels()
{
	nk_glfw3_new_frame(&glfw);
	for (auto& panel : vUIPanels)
	{
		panel->Draw();
	}
	nk_glfw3_render(&glfw, NK_ANTI_ALIASING_ON, 512 * 1024, 128 * 1024);
}

