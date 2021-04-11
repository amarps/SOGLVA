#include "UISystem.h"

void UISystem::Init()
{
	context = nk_glfw3_init(&glfw, rendering.window, NK_GLFW3_INSTALL_CALLBACKS);

	{
		nk_font_atlas* atlas;
		nk_glfw3_font_stash_begin(&glfw, &atlas);
		nk_glfw3_font_stash_end(&glfw);
	}

	set_style(context, THEME_WHITE);

	vIUIPanels.push_back(std::make_unique< UI::Panel::FPSCounter>(context, rendering, "FPS Counter"));
	vIUIPanels.push_back(std::make_unique< UI::Panel::Property>(context, rendering, "Property"));

	for (auto& panel : vIUIPanels)
	{
		panel->Setup();
	}
}

void UISystem::Update()
{
	nk_glfw3_new_frame(&glfw);
	for (auto& panel : vIUIPanels)
	{
		panel->Draw();
	}
	nk_glfw3_render(&glfw, NK_ANTI_ALIASING_ON, 512 * 1024, 128 * 1024);
}

void UISystem::Exit()
{
	delete context;
}
