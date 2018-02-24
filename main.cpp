#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Core/Common/Shader.h>
#include <Core/Engine/Logger.h>

int main()
{
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

    //Shader test
    Core::Shader("../res/shaders/vertex.vs", "../res/shaders/fragment.fs");
    Core::Logger::Log("Test", "main");

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.5f, 0.3f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}