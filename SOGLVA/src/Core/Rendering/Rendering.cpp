#include "Rendering.h"

Rendering::Rendering()
{
	SetupGLFWWindow();
	ConfigureOGLFunction();
}

Rendering::~Rendering()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Rendering::SetupGLFWWindow()
{
	/// initialize glfw context for opengl
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);

#ifdef _DEBUG
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif

#ifndef _DEBUG
	/// remove tittle bar
	glfwWindowHint(GLFW_DECORATED, false);
#endif // !_DEBUG


}

void Rendering::ConfigureOGLFunction()
{
	/// Window Creation
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, AppName.c_str(), NULL, NULL);
	glfwMakeContextCurrent(window);

	// get the HWND form glfw
	hwNative = glfwGetWin32Window(window);

	/// sets the user-defined pointer of the specified window. 
	/// The current value is retained until the window is destroyed.
	glfwSetWindowUserPointer(window, this); // i still dont know how to use this one

	/// Initialize GLEW to load opengl API
	if (glewInit() != GLEW_OK)
	{
		// something wrong with your glew/glfw 
		// tip from me check your linker, include dir and build settings
		// and check readme.md for info of this project
		throw std::runtime_error("Failed to initialize glew");
	}

	glfwSetFramebufferSizeCallback(this->window, this->framebuffer_size_callback);

	glEnable(GL_MULTISAMPLE);
}

void Rendering::ClearWindow()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(ClearColor[0], ClearColor[1], ClearColor[2], ClearColor[3]);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Rendering::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}
