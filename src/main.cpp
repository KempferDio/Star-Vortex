#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Core/Renderer.h>
#include <Core/ResourceManager.h>
#include <Core/Logger.h>

int main()
{

    Core::Renderer *Render = new Core::Renderer(800, 600, "Test");
    Render->InitBaseSettings();
    //glViewport(0, 0, 800, 600);

    Core::ResourceManager::LoadShader("../../res/shaders/vertex.vs", "../../res/shaders/fragment.fs", "Shader");
    Core::ResourceManager::GetShader("Shader").setInt("image", 0);

    Core::ResourceManager::LoadTexture("../../res/textures/wall.jpg", "Texture");

    while (!glfwWindowShouldClose(Render->GetWindow()))
    {
        Render->ClearScreen();
        glm::mat4 projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, 0.1f, 100.0f);
        Core::ResourceManager::GetShader("Shader").setMatrix4("projection", projection);

#ifdef DEBUG
        std::cout << "Projection" << std::endl;
        Render->printMatrix(projection);
#endif

        glm::vec2 position(200.0f, 200.0f);
        glm::vec2 size(500.0f, 500.0f);
        glm::vec3 color(1.0f, 0.5f, 0.5f);

        Render->Draw("Texture",
                     "Shader",
                     position, size, 0.0f, color);

        glfwPollEvents();
        glfwSwapBuffers(Render->GetWindow());
    }

    Render->TerminateRenderer();
    Core::ResourceManager::FreeResources();
    delete Render;
    return 0;
}