#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

#include <Core/Engine/Logger.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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
  char *loadShaderFromFile(const char *path);
};
}

#endif //SHADER_H
