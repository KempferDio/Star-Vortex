#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <Core/Engine/Logger.h>
#include <iostream>
#include <stdio.h>

#define SHADER_BUFFER_SIZE 512

namespace Core
{
class Shader
{
public:
  Shader(const char *vertexPath, const char *fragmentPath);
  void Use();

private:
  GLuint Id;
  void checkCompileErrors(GLuint shader, const char *type);
  void checkLinkErrors();
  std::string loadShaderFromFile(const char *path);
};
}

#endif //SHADER_H
