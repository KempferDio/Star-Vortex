#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Core/Renderer.h>
#include <Core/ResourceManager.h>
#include <Core/Logger.h>

int main()
{

    Core::Renderer* Render = new Core::Renderer(800, 600, "Test");
    Render->InitBaseSettings();
    Core::ResourceManager::LoadShader("../../res/shaders/vertex.vs", "../../res/shaders/fragment.fs", "Shader");
    Core::ResourceManager::GetShader("Shader").setInt("image", 0);
    Core::ResourceManager::LoadTexture("../../res/texture/main.png", "Texture");

    while (!glfwWindowShouldClose(Render->GetWindow()))
    {
        Render->ClearScreen();
        Core::ResourceManager::GetShader("Shader").Use();

        Render->Draw(Core::ResourceManager::GetTexture("Texture"),
                    Core::ResourceManager::GetShader("Shader"),
                    glm::vec3(200, 200, 0), glm::vec2(0, 0), 45.0f, glm::vec3(1.0f, 0.5f, 0.3f));

        glfwPollEvents();
        glfwSwapBuffers(Render->GetWindow());
    }

    Render->TerminateRenderer();
    Core::ResourceManager::FreeResources();
    delete Render;
    return 0;
}