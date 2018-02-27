#include <Core/Common/Shader.h>

using namespace Core;

Shader::Shader()
{
    //Default ctor
    //For map in resource manager
}

Shader::Shader(std::string vertexCode, std::string fragmentCode)
{
    //Logger::Log(vertexCode, "Shader::Shader(string, string)");
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

void Shader::Use()
{
    glUseProgram(Id);
}

void Shader::checkCompileErrors(GLuint shader)
{
    int success;
    char info[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, info);
        Logger::Log(info, "Shader::checkCompileErrors");
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

void Shader::setBool(const char *name, bool value) const
{
    glUniform1i(glGetUniformLocation(Id, name), (int)value);
}

void Shader::setInt(const char *name, int value) const
{
    glUniform1i(glGetUniformLocation(Id, name), value);
}

void Shader::setFloat(const char *name, float value) const
{
    glUniform1f(glGetUniformLocation(Id, name), value);
}

void Shader::setVec3f(const char *name, glm::vec3 value) const
{
    glUniform3f(glGetUniformLocation(Id, name), value.x, value.y, value.z);
}

void Shader::setVec3f(const char *name, float value1, float value2, float value3) const
{
    glUniform3f(glGetUniformLocation(Id, name), value1, value2, value3);
}

void Shader::setMatrix4(const char *name, glm::mat4 mat)
{
    glUniformMatrix4fv(glGetUniformLocation(Id, name), 1, GL_FALSE, glm::value_ptr(mat));
}