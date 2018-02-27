#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Core/Common/Texture.h>
#include <Core/Common/Shader.h>
#include <Core/Engine/GameWindow.h>

namespace Core
{
class Renderer
{
public:
  //
  Renderer(unsigned int width, unsigned int height, const char *title);
  ~Renderer();
  void ClearScreen();
  void Draw(Texture &texture, Shader &shader, glm::vec3 position,
            glm::vec2 size, GLfloat rotate, glm::vec3 color);
  void InitBaseSettings();
  void TerminateRenderer();
  GLFWwindow *GetWindow();
  GameWindow Window;

private:
  GLuint VAO;
};
}

#endif //RENDERER_H