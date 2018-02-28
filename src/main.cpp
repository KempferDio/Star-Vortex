#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Core/Renderer.h>
#include <Core/ResourceManager.h>
#include <Core/Logger.h>

int main()
{

    Core::Renderer *Render = new Core::Renderer(800, 600, "Test");
    Render->InitBaseSettings();
    glm::mat4 projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);
    Core::ResourceManager::LoadShader("../../res/shaders/vertex.vs", "../../res/shaders/fragment.fs", "Shader");
    Core::ResourceManager::GetShader("Shader").setInt("image", 0);
    Core::ResourceManager::GetShader("Shader").setMatrix4("projection", projection);
    Core::ResourceManager::LoadTexture("../../res/textures/wall.jpg", "Texture");

    glm::vec2 position(0, 0);
    glm::vec2 size(5, 5);
    glm::vec3 color(1.0f, 0.5f, 0.5f);

    while (!glfwWindowShouldClose(Render->GetWindow()))
    {
        Render->ClearScreen();

        Render->Draw(Core::ResourceManager::GetTexture("Texture"),
                     Core::ResourceManager::GetShader("Shader"),
                     position, size, 0.0f, color);

        glfwPollEvents();
        glfwSwapBuffers(Render->GetWindow());
    }

    Render->TerminateRenderer();
    Core::ResourceManager::FreeResources();
    delete Render;
    return 0;
}