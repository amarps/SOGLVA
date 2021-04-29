#pragma once
#include "SOGLVA_API.h"
#include "SOGLVA.h"
#include "SYSTEM/SOGLVASystem.h"

#ifdef _DEBUG
int main()
{
	SOGLVA::Initialize();
	SOGLVA::RunApp();
}
#endif // _DEBUG