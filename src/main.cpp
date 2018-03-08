#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Core/Renderer.h>
#include <Core/ResourceManager.h>
#include <Core/Logger.h>

void key_callback(GLFWwindow* win, int key, int scancode, int action, int mods);
void framebuffer_size_callback(GLFWwindow *win, int width, int height);

    glm::vec3 position(1.0f, 1.0f, 0.0f);
    glm::vec3 size(100.0f);
    glm::vec3 color(0.2f, 0.8f, 0.5f);

int main()
{

    Core::Renderer *Render = new Core::Renderer(1980, 1090, "Test");
    Render->InitBaseSettings();
    

    Core::ResourceManager::LoadShader("../../res/shaders/vertex.vs", "../../res/shaders/fragment.fs", "Shader");
    Core::ResourceManager::GetShader("Shader").setInt("image", 0);

    Core::ResourceManager::LoadTexture("../../res/textures/wall.jpg", "Texture");
    glfwSetKeyCallback(Render->GetWindow(), key_callback);
    glfwSetFramebufferSizeCallback(Render->GetWindow(), framebuffer_size_callback);

    while (!glfwWindowShouldClose(Render->GetWindow()))
    {
        Render->ClearScreen();

        Core::ResourceManager::GetShader("Shader").Use();

        //Rework this
        glm::mat4 projection = glm::ortho(0.0f, (float)Render->Window.Width, 0.0f, (float)Render->Window.Height, -1.0f, 10.0f);
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

        Core::ResourceManager::GetShader("Shader").setMatrix4("projection", projection);
        Core::ResourceManager::GetShader("Shader").setMatrix4("view", view);

       

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

void key_callback(GLFWwindow* win, int key, int scancode, int action, int mods) {
    if(key == GLFW_KEY_UP && action ==  GLFW_PRESS) {
        position.y += 1.1f;
    }

    if(key == GLFW_KEY_DOWN && action ==  GLFW_PRESS) {
        position.y -= 1.1f;
    }

    if(key == GLFW_KEY_RIGHT && action ==  GLFW_PRESS) {
        position.x += 1.1f;
    }

    if(key == GLFW_KEY_LEFT && action ==  GLFW_PRESS) {
        position.x -= 1.1f;
    }

    if(key == GLFW_KEY_E && action ==  GLFW_PRESS) {
        position.z -= 1.0f;
    }

    if(key == GLFW_KEY_Q && action ==  GLFW_PRESS) {
        position.z += 1.0f;
    }
}

void framebuffer_size_callback(GLFWwindow *win, int width, int height) {
    glViewport(0, 0, width, height);
}