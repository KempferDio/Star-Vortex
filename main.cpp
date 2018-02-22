
#include <Engine/Engine.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
    if (!glfwInit())
    {
        return 1;
    }

    GLFWwindow *window = glfwCreateWindow(640, 480, "Title", NULL, NULL);

    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}