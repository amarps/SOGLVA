#include "SOGLVASystem.h"

namespace SOGLVA
{
	HWND Initialize()
	{
		application = std::make_unique<Soglva>();
		application->Initialize();
		return application->rendering->hwNative;
	}

	void RunApp()
	{
		if (application)
			application->Run();
	}

	void Destroy()
	{
		if (application)
		{
			application->Quit();
			application.release();
		}
	}
}
