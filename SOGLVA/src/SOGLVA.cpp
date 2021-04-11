#include "SOGLVA.h"

bool SOGLVA::Init()
{
	rendering = std::make_unique<RenderingSystem>();
	ui = std::make_unique<UISystem>(*rendering.get());

	if (!rendering->Init())
	{
		return 0;
	}
	ui->Init();
	while (!glfwWindowShouldClose(rendering->window))
	{
		rendering->ClearWindow();


		ui->Update();
		float currentFrame = glfwGetTime();
		rendering->deltaTime = currentFrame - rendering->lastFrame;
		rendering->lastFrame = currentFrame;
		/// Swap the buffer and poll IO events (keys pressed/released, mouse moved etc.)
		glfwSwapBuffers(rendering->window);
		glfwPollEvents();
	}

	return 1;
}