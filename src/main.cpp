#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Core/Engine/Renderer.h>
#include <Core/Engine/ResourceManager.h>
#include <Core/Engine/Logger.h>

int main()
{

    Core::Renderer Render(800, 600, "Test");
    Render.InitBaseSettings();
    Core::ResourceManager::LoadShader("../../res/shaders/vertex.vs", "../../res/shaders/fragment.fs", "Shader");

    while (!glfwWindowShouldClose(Render.GetWindow()))
    {
        Render.ClearScreen();
        Core::ResourceManager::GetShader("Shader").Use();

        glfwPollEvents();
        glfwSwapBuffers(Render.GetWindow());
    }

    Render.TerminateRenderer();
    Core::ResourceManager::FreeResources();
    return 0;
}