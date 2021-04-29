#include "SOGLVA.h"

#include "InputHandler/DefaultInput.h"

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_KEYSTATE_BASED_INPUT
#define NK_IMPLEMENTATION
#define NK_GLFW_GL3_IMPLEMENTATION
#include <nuklear.h>
#include <glfw_opengl3/nuklear_glfw_gl3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


Soglva::Soglva()
{
}

Soglva::~Soglva()
{
	m_quit = true;
	_dllUpdater->m_dllFunction["Exit"]();
	sceneManager.release();
	ui.release();
	rendering.release();
}

void Soglva::Initialize()
{
	rendering = std::make_unique<Rendering>();
	ui = std::make_unique<UISystem>(*rendering.get());
	sceneManager = std::make_unique<SceneManager>();
	_entryPointMap["Start"] = NULL;
	_entryPointMap["Update"] = NULL;
	_entryPointMap["Exit"] = NULL;
	_dllUpdater = new RuntimeDLLUpdate("D:/projects/C++/SOGLVA/x64/Debug/SampleProject.dll", _entryPointMap);


	sceneManager->CreateScene();
	_dllUpdater->m_dllFunction["Start"]();
}

bool Soglva::IsQuit()
{
	return m_quit;
}

void Soglva::Quit()
{
	m_quit = true;
}

void Soglva::Run()
{
	while (!IsQuit())
	{
		rendering->ClearWindow();

		_dllUpdater->m_dllFunction["Update"]();

		sceneManager->GetCurrentScene()->Update();

		ui->DrawUiPanels();

		float currentFrame = glfwGetTime();

		rendering->deltaTime = currentFrame - rendering->lastFrame;
		rendering->lastFrame = currentFrame;
			
		glfwSwapBuffers(rendering->window);
		DefaultKeyboardInput(*rendering);
		glfwPollEvents();
	}
}
