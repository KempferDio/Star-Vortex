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
    if(Window.WindowPtr == NULL) {
        Logger::Log("Failed to create GLFW window", "Renderer::Renderer()");
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(GetWindow());

    camera = new Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f));
}

Renderer::~Renderer()
{
    glDeleteVertexArrays(1, &VAO);
    glfwDestroyWindow(GetWindow());
    glfwTerminate();
    delete camera;
}

GLFWwindow *Renderer::GetWindow()
{
    return Window.WindowPtr;
}

//
void Renderer::Draw(const char *textureName, const char *shaderName, glm::vec3 position,
                    glm::vec2 size,
                    GLfloat rotate, glm::vec3 color)
{
     Core::ResourceManager::GetShader(shaderName).Use();
    //Set projection matrix
    projectionMatrix = glm::ortho(0.0f, (float)Window.Width, 0.0f, (float)Window.Height, 0.0f, 10.0f);
    viewMatrix = camera->getViewMatrix();
   

    //This will be in Component of Entity - "Drawable"
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::scale(model, glm::vec3(size, 1.0f));
    model = glm::rotate(model, rotate, glm::vec3(0.0f, 0.0f, 1.0f));

    Core::ResourceManager::GetShader(shaderName).setMatrix4("model", model);
    Core::ResourceManager::GetShader(shaderName).setMatrix4("view", viewMatrix);
    Core::ResourceManager::GetShader(shaderName).setMatrix4("projection", projectionMatrix);
    Core::ResourceManager::GetShader(shaderName).setVec3f("spriteColor", color);

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

    glViewport(0, 0, Window.Width, Window.Height);
    GLfloat vertices[] = {
        //Position         Texture 
        0.5f, -0.5f, 0.0f,  0.5f, -0.5f,
        0.5f, 0.5f, 0.0f,   0.5f,  0.5f,
        -0.5f, 0.5f, 0.0f, -0.5f,  0.5f,

        -0.5f, -0.5f, 0.0f, -0.5f, -0.5f,
        0.5f,  -0.5f,  0.0f,   0.5f, -0.5f,
        -0.5f,  0.5f,  0.0f,  -0.5f,  0.5f
    };


    GLuint VBO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void *)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void *)(3 * sizeof(GLfloat)));
    
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
    glDeleteVertexArrays(1, &VAO);
    glfwDestroyWindow(GetWindow());
    glfwTerminate();
}
