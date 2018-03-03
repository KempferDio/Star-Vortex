#include <Core/Renderer.h>

using namespace Core;

Renderer::Renderer(unsigned int width, unsigned int height, const char *title)
{
    Window.Width = width;
    Window.Height = height;
    Window.Title = title;

    if (!glfwInit())
    {
        Core::Logger::Log("Failed to initialize GLFW", "Renderer::setupWindow");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Window.WindowPtr = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwMakeContextCurrent(GetWindow());
}

Renderer::~Renderer()
{
    glfwDestroyWindow(GetWindow());
    glfwTerminate();
}

GLFWwindow *Renderer::GetWindow()
{
    return Window.WindowPtr;
}

//
void Renderer::Draw(Texture &texture, Shader &shader, glm::vec3 position,
                    glm::vec2 size,
                    GLfloat rotate, glm::vec3 color)
{
    shader.Use();
    // glm::mat4 model;

    // model = glm::translate(model, glm::vec3(position));

    // model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    // model = glm::rotate(model, rotate, glm::vec3(0.0f, 0.0f, 1.0f));
    // model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

    // model = glm::scale(model, glm::vec3(size, 1.0f));

    // shader.setMatrix4("model", model);
    shader.setVec3f("spriteColor", color);

    glActiveTexture(GL_TEXTURE0);
    texture.Bind();

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void Renderer::InitBaseSettings()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Core::Logger::Log("Failed to initialize GLAD", "Renderer::Renderer()");
    }
    GLuint VBO;
    GLfloat vertices[] = {
        -1.0f, 1.0f, -1.0f, 1.0f,
        1.0f, -1.0f, 1.0f, -1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,

        -1.0f, 1.0f, -1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, 1.0f, -1.0f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid *)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Renderer::ClearScreen()
{
    glClearColor(0.5f, 0.3f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::TerminateRenderer()
{
    Logger::Log("Renderer is dead", "~Renderer");
    glfwDestroyWindow(GetWindow());
    glfwTerminate();
}