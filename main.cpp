#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Core/Common/Shader.h>
#include <Core/Engine/Logger.h>

bool Core::Logger::isLogFileCreated = false;

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

    Core::Shader("../res/shaders/vertex.vs", "../res/shaders/fragment.fs");

    system("PAUSE");
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}