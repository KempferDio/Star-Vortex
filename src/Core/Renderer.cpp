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
    glDeleteVertexArrays(1, &VAO);
    glfwDestroyWindow(GetWindow());
    glfwTerminate();
}

GLFWwindow *Renderer::GetWindow()
{
    return Window.WindowPtr;
}

//
void Renderer::Draw(const char *textureName, const char *shaderName, glm::vec2 position,
                    glm::vec2 size,
                    GLfloat rotate, glm::vec3 color)
{
    Core::ResourceManager::GetShader(shaderName).Use();
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, glm::vec3(position, 0.0f));

    // model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    // model = glm::rotate(model, rotate, glm::vec3(0.0f, 0.0f, 1.0f));
    // model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

    // model = glm::scale(model, glm::vec3(size, 1.0f));

#ifdef DEBUG
    std::cout << "Model" << std::endl;
    printMatrix(model);
#endif

    Core::ResourceManager::GetShader(shaderName).setVec3f("spriteColor", color);
    Core::ResourceManager::GetShader(shaderName).setMatrix4("model", model);

    glActiveTexture(GL_TEXTURE0);
    Core::ResourceManager::GetTexture(textureName).Bind();

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
        // Position // Texture
        -1.0f, 1.0f, -1.0f, 1.0f,
        1.0f, -1.0f, 1.0f, -1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,

        -1.0f, 1.0f, -1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, 1.0f, -1.0f};

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *)0);
    glEnableVertexAttribArray(0);
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
