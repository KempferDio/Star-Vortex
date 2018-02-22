#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <sstream>

namespace Core
{
class Shader
{
public:
  Shader(const char *vertexPath, const char *fragmentPath);
  void Use();

private:
  GLuint Id;
};
}

#endif //SHADER_H
