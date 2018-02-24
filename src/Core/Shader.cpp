#include <Core/Common/Shader.h>

using namespace Core;

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
    //Loading shaders from files
    std::string vertexCode = loadShaderFromFile(vertexPath);
    std::string fragmentCode = loadShaderFromFile(fragmentPath);

    const char *vertexShader = vertexCode.c_str();
    const char *fragmentShader = fragmentCode.c_str();

    GLuint vertex, fragment;
    //Create vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexShader, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");
    //Create fragment shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentShader, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");
    //Create shader program
    Id = glCreateProgram();
    glAttachShader(Id, vertex);
    glAttachShader(Id, fragment);
    glLinkProgram(Id);
    checkLinkErrors();

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::Use()
{
    glUseProgram(Id);
}

void setVec3(const char *name, glm::vec3)
{
}

void Shader::checkCompileErrors(GLuint shader, const char *type)
{
    int success;
    char info[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, info);
        Logger::Log(info, type);
    }
}

void Shader::checkLinkErrors()
{
    int success;
    char info[512];

    glGetProgramiv(Id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(Id, 512, NULL, info);
        Logger::Log(info, "SHADER::checkLinkErrors");
    }
}

std::string Shader::loadShaderFromFile(const char *path)
{
    std::string shader;
    std::ifstream shaderFile;
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        shaderFile.open(path);
        std::stringstream shaderStream;

        shaderStream << shaderFile.rdbuf();

        shader = shaderStream.str();

        shaderFile.close();
    }
    catch (std::ifstream::failure e)
    {
        Logger::Log("Can't read file", "Shader::loadShaderFromFile");
    }

    return shader;
}

void Shader::setVec3(const char *name, glm::vec3) const
{
}

void Shader::setVec3(const char *name, float value1, float value2, float value3) const
{
}