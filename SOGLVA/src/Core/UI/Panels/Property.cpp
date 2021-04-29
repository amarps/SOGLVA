#include "Property.h"
#include "ManagedObject/Components/Camera.h"

void Property::Draw()
{
	context->style.window.fixed_background = nk_style_item_color(nk_rgba(255, 255, 255, 255));
	context->style.text.color = nk_rgb(0, 0, 0);
	context->style.window.border_color = nk_rgba(204, 213, 240, 255);
	if (nk_begin(context, name.c_str(), nk_rect(rendering.SCREEN_WIDTH - 200, rendering.SCREEN_HEIGHT - 400, 200, 400),
		NK_WINDOW_BORDER | NK_WINDOW_MOVABLE | NK_WINDOW_SCALABLE |
		NK_WINDOW_MINIMIZABLE | NK_WINDOW_CLOSABLE | NK_WINDOW_TITLE))
	{
		nk_layout_row_dynamic(context, 25, 1);
		nk_property_float(context, "Camera Speed", 0, &Camera::get().MovementSpeed, 50, 1, 0.1);
	}
	nk_end(context);
}