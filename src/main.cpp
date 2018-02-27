#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Core/Engine/Renderer.h>
#include <Core/Engine/ResourceManager.h>
#include <Core/Engine/Logger.h>

int main()
{
    Core::Renderer::SetupWindow(800, 600, "Test");
    Core::Renderer::InitBaseSettings();
    Core::ResourceManager::LoadShader("../../res/shaders/vertex.vs", "../../res/shaders/fragment.fs", "Shader");

    while (!glfwWindowShouldClose(Core::Renderer::Window))
    {
        Core::Renderer::ClearScreen();
        Core::ResourceManager::GetShader("Shader").Use();

        glfwPollEvents();
        glfwSwapBuffers(Core::Renderer::Window);
    }

    Core::Renderer::TerminateRenderer();
    Core::ResourceManager::FreeResources();
    return 0;
}