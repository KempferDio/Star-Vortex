#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Core/Texture.h>
#include <Core/Shader.h>
#include <Core/GameWindow.h>
#include <Core/ResourceManager.h>
#include <Core/Camera.h>

namespace Core
{
class Renderer
{
public:
  //
  Renderer(unsigned int width, unsigned int height, const char *title);
  ~Renderer();
  void ClearScreen();
  void Draw(const char *textureName, const char *shaderName, glm::vec3 position,
            glm::vec2 size, GLfloat rotate, glm::vec3 color);
  void InitBaseSettings();
  void TerminateRenderer();
  GLFWwindow *GetWindow();
  GameWindow Window;
  Camera* camera;
  
private:
  GLuint VAO;
  //Main view and projection matrix
  //Test
  glm::mat4 viewMatrix;
  glm::mat4 projectionMatrix;
};
}

#endif //RENDERER_H