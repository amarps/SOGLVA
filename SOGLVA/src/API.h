#pragma once
#ifndef _DEBUG

#ifdef SOGLVA_EXPORTS
#define SOGLVA_API __declspec(dllexport)
#else
#define SOGLVA_API __declspec(dllimport)
#endif

extern "C" SOGLVA_API void SOGLVARun();

extern "C" SOGLVA_API void SOGLVAShowWindow();

extern "C" SOGLVA_API void SOGLVASetParentWindow(HWND parentWindow);

extern "C" SOGLVA_API HWND SOGLVAGetHWnd();

#endif