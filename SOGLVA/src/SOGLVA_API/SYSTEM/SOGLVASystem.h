#pragma once

#include "../SOGLVA_API.h"

namespace SOGLVA
{
	extern "C" HWND EXPORT Initialize();

	extern "C" void EXPORT RunApp();

	extern "C" void EXPORT Destroy();
}
