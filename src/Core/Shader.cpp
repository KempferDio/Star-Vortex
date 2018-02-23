#include <Core/Common/Shader.h>

using namespace Core;

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
    //Loading shaders from files
    std::string vertexCode;
    std::string fragmentCode;

    std::ifstream vertexFile;
    std::ifstream fragmentFile;

    vertexFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragmentFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        vertexFile.open(vertexPath);
        fragmentFile.open(fragmentPath);

        std::stringstream vertexStream;
        std::stringstream fragmentStream;

        vertexStream << vertexFile.rdbuf();
        fragmentStream << fragmentFile.rdbuf();

        vertexCode = vertexStream.str();
        fragmentCode = fragmentStream.str();

        fragmentFile.close();
        vertexFile.close();
    }
    catch (std::ifstream::failure e)
    {
        Logger::Log("Can't read shader file",
                    "Shader::Shader");
    }

    const char *vertexShader = vertexCode.c_str();
    const char *fragmentShader = fragmentCode.c_str();

    GLuint vertex, fragment;
    //Create vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexShader, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex);
    //Create fragment shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentShader, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment);
    //Create shader program
    Id = glCreateProgram();
    glAttachShader(Id, vertex);
    glAttachShader(Id, fragment);
    glLinkProgram(Id);
    checkLinkErrors();

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::checkCompileErrors(GLuint shader)
{
    int success;
    char info[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, info);
        Logger::Log(info, "SHADER::checkCompileErrors");
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

void Shader::Use()
{
    glUseProgram(Id);
}
