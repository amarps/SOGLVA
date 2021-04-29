#pragma once
#include "RenderingDef.h"

/// \cond
#include <iostream>
/// \endcond

class Rendering
{
private:
	/// @brief 
	/// resize callback for opengl viewport size context to new window size
	/// @param window : GLFW window that want to implement resize callback
	/// @param width : window width
	/// @param height : window height
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	/// @brief 
	/// intialize glfw window and startup configuration handler
	void SetupGLFWWindow();

	/// <summary>
	/// </summary>

	/**
	- Create window in glfw
	- load Opengl API via glew
	- set window callback
	*/
	void ConfigureOGLFunction();

public:
	Rendering();
	~Rendering();

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	GLFWwindow* window;

	/// HWND of glfwWindow for use in win32 apps.
	HWND hwNative;

	/// default screen width.
	static inline int SCREEN_WIDTH = 800;

	/// default screen height
	static inline int SCREEN_HEIGHT = 600;

	/// default application name
	static inline std::string AppName = "Default";

	/// <summary>
	/// Clear Color contain 4 color in RGBA which will be used in clear in ClearWindow Method for clearing window
	/// </summary>
	static inline float ClearColor[4] = { 0.05f, 0.05f, 0.05f, 1.0f };

	/// <summary>
	/// Clear the window using static rendering::ClearColor 
	/// </summary>
	void ClearWindow();
};

