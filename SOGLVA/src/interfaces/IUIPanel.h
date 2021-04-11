#pragma once

class IUIPanel
{
public:
	// will be executed before main loop and after initialize
	virtual void Setup() = 0;

	// will be executed when inside main loop
	virtual void Draw() = 0;
};