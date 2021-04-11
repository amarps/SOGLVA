#pragma once

#define GLEW_STATIC
#include <glew/include/GL/glew.h>
#include <glfw/include/GLFW/glfw3.h>

#define GLFW_EXPOSE_NATIVE_WIN32
#include <glfw/include/GLFW/glfw3native.h>

#include <Windows.h>

#include "common/standard.h"

class RenderingSystem
{
private:
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

public:
	RenderingSystem() = default;
	~RenderingSystem()
	{
		delete window;
	}

//	Members -------------------------------------------------
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	GLFWwindow* window;
	HWND hwNative;


	static inline int SCREEN_WIDTH = 800;
	static inline int SCREEN_HEIGHT = 600;
	static inline std::string AppName = "Default";
	static inline float ClearColor[4] = { 0.1f, 0.1f, 0.4f, 1.0f };

//	Method -------------------------------------------------
	bool Init();
	void ClearWindow();
};

