#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Core/Engine/Logger.h>
#include <iostream>

#define SHADER_BUFFER_SIZE 512

namespace Core
{
class Shader
{
public:
  Shader();
  Shader(std::string vertexCode, std::string fragmentCode);
  void Use();
  GLuint Id;

  void setBool(const char *name, bool value) const;
  void setInt(const char *name, int value) const;
  void setFloat(const char *name, float value) const;
  void setVec3f(const char *name, glm::vec3 value) const;
  void setVec3f(const char *name, float value1, float value2, float value3) const;
  void setMatrix4(const char *name, glm::mat4 mat);

private:
  void checkCompileErrors(GLuint shader);
  void checkLinkErrors();
};
}

#endif //SHADER_H
