#include "FPSCounter.h"

#include <string>

void FPSCounter::Draw()
{
	// remove window backgorund
	context->style.window.fixed_background = nk_style_item_hide();
	if (nk_begin(context, name.c_str(), nk_rect(0, 0, 300, 100),
		NK_WINDOW_NO_INPUT))
	{
		nk_layout_row_dynamic(context, 20, 1);
		fpsText = "FPS:" + std::to_string(1 / rendering.deltaTime).substr(0, 5);
		context->style.text.color = nk_rgb(255, 204, 0);
		nk_label(context, fpsText.c_str(), NK_TEXT_LEFT);
		context->style.text.color = nk_rgb(255, 204, 255);
		nk_label(context, "Type R to show Settings Window", NK_TEXT_LEFT);
	}
	nk_end(context);
}