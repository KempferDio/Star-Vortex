#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>

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

  void setVec3(const char *name, glm::vec3) const;
  void setVec3(const char *name, float value1, float value2, float value3) const;

private:
  GLuint Id;
  void checkCompileErrors(GLuint shader, const char *type);
  void checkLinkErrors();
  std::string loadShaderFromFile(const char *path);
};
}

#endif //SHADER_H
