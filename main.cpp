
#include <Core/Engine/Engine.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
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
    system("PAUSE");
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}