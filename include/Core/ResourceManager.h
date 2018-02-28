#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <glad/glad.h>
#include <map>
#include <fstream>
#include <sstream>
#include <Core/Shader.h>
#include <Core/Texture.h>
#include <Core/Logger.h>
#include <SOIL/SOIL.h>

/*
    Base resource manager
*/

namespace Core
{
class ResourceManager
{
public:
  static std::map<std::string, Shader> Shaders;
  static std::map<std::string, Texture> Textures;
  static void LoadShader(const char *vertexPath, const char *fragmentPath, std::string name);
  static void LoadTexture(const char *path, std::string name);
  static Shader &GetShader(const char *name);
  static Texture &GetTexture(const char *name);
  static void FreeResources();

private:
  static std::string loadShaderFile(const char *shaderPath);
  static Texture loadTextureFromFile(const char *path);

  ResourceManager();
};
}

#endif //RESOURCE_MANAGER_H