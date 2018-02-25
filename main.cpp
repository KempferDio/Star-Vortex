#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Core/Engine/ResourceManager.h>
#include <Core/Engine/Logger.h>

int main()
{
    //TODO: Renderer
    if (!glfwInit())
    {
        return 1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(640, 480, "Title", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Core::Logger::Log("Failed to initialize GLAD", "main");
        return -1;
    }

    Core::ResourceManager::LoadShader("../res/shaders/vertex.vs", "../res/shaders/fragment.fs", "Test shader");

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.5f, 0.3f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    Core::ResourceManager::FreeResources();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}