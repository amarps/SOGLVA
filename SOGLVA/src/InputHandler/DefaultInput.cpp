#include "DefaultInput.h"
#include "ManagedObject/Components/Camera.h"

#include "SOGLVA_API/SOGLVA_API.h"
#include "SOGLVA_API/SYSTEM/SOGLVASystem.h"

void DefaultKeyboardInput(Rendering& rendering)
{
    // camera
    if (glfwGetKey(rendering.window, GLFW_KEY_W) == GLFW_PRESS)
        Camera::get().ProcessKeyboard(Camera::FORWARD, rendering.deltaTime);
    if (glfwGetKey(rendering.window, GLFW_KEY_S) == GLFW_PRESS)
        Camera::get().ProcessKeyboard(Camera::BACKWARD, rendering.deltaTime);
    if (glfwGetKey(rendering.window, GLFW_KEY_A) == GLFW_PRESS)
        Camera::get().ProcessKeyboard(Camera::LEFT, rendering.deltaTime);
    if (glfwGetKey(rendering.window, GLFW_KEY_D) == GLFW_PRESS)
        Camera::get().ProcessKeyboard(Camera::RIGHT, rendering.deltaTime);

    //// camera height position
    if (glfwGetKey(rendering.window, GLFW_KEY_R) == GLFW_PRESS)
    {
        SOGLVA::Destroy();
        return;
    }
    if (glfwGetKey(rendering.window, GLFW_KEY_SPACE) == GLFW_PRESS)
    {
            
    }
    if (glfwGetKey(rendering.window, GLFW_KEY_F) == GLFW_PRESS)
    {

    }
    // camera rotation key
    if (glfwGetKey(rendering.window, GLFW_KEY_Z) == GLFW_PRESS)
    {
        Camera::get().ProcessMouseMovement((-Camera::get().MovementSpeed * 75) * rendering.deltaTime, 0.0f);
    }
    if (glfwGetKey(rendering.window, GLFW_KEY_X) == GLFW_PRESS)
    {
        Camera::get().ProcessMouseMovement((Camera::get().MovementSpeed * 75) * rendering.deltaTime, 0.0f);
    }
    if (glfwGetKey(rendering.window, GLFW_KEY_Q) == GLFW_PRESS)
    {
        Camera::get().ProcessMouseMovement(0.0f, (-Camera::get().MovementSpeed * 75) * rendering.deltaTime);
    }
    if (glfwGetKey(rendering.window, GLFW_KEY_E) == GLFW_PRESS)
    {
        Camera::get().ProcessMouseMovement(0.0f, (Camera::get().MovementSpeed * 75) * rendering.deltaTime);
    }
}