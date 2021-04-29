#pragma once

class IUIDrawable
{
public:
	// will be executed when inside main loop
	virtual void Draw() = 0;
};