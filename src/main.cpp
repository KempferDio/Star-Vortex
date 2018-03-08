#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Core/Renderer.h>
#include <Core/ResourceManager.h>
#include <Core/Logger.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

//Test methods
void key_callback(GLFWwindow* win, int key, int scancode, int action, int mods);
void framebuffer_size_callback(GLFWwindow *win, int width, int height);

//Test values
glm::vec3 position(200.0f, 200.0f, -1.0f);
glm::vec3 size(100.0f);
glm::vec3 color(0.2f, 0.8f, 0.5f);

//std::chrono::time_point<std::chrono::system_clock> Core::Logger::startTime = std::chrono::system_clock::now();
clock_t Core::Logger::startTime = clock();


int main()
{

#ifdef DEBUG
        Core::Logger::Log("DEBUG MOD ACTIVATED", "main");
#endif
    Core::Renderer *Render = new Core::Renderer(SCREEN_WIDTH, SCREEN_HEIGHT, "Test");
    Render->InitBaseSettings();
  
    Core::ResourceManager::LoadShader("../../res/shaders/vertex.vs", "../../res/shaders/fragment.fs", "Shader");

    Core::ResourceManager::LoadTexture("../../res/textures/wall.jpg", "Texture");

    glfwSetKeyCallback(Render->GetWindow(), key_callback);
    glfwSetFramebufferSizeCallback(Render->GetWindow(), framebuffer_size_callback);

    while (!glfwWindowShouldClose(Render->GetWindow()))
    {
        Render->ClearScreen();

        Render->Draw("Texture", "Shader", position, size, 0.0f, color);

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
        position.y += 5.1f;
    }

    if(key == GLFW_KEY_DOWN && action ==  GLFW_PRESS) {
        position.y -= 5.1f;
    }

    if(key == GLFW_KEY_RIGHT && action ==  GLFW_PRESS) {
        position.x += 5.1f;
    }

    if(key == GLFW_KEY_LEFT && action ==  GLFW_PRESS) {
        position.x -= 5.1f;
    }

    if(key == GLFW_KEY_E && action ==  GLFW_PRESS) {
        position.z -= 1.0f;
    }

    if(key == GLFW_KEY_Q && action ==  GLFW_PRESS) {
        position.z += 1.0f;
    }

    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(win, true);
    }
}

void framebuffer_size_callback(GLFWwindow *win, int width, int height) {
    glViewport(0, 0, width, height);
}