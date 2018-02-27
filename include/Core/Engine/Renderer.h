#ifndef RENDERER_H
#define RENDERER_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Core/Common/Texture.h>
#include <Core/Common/Shader.h>

namespace Core
{
class Renderer
{
public:
  //
  static void ClearScreen();
  static void SetupWindow(unsigned int width, unsigned int height, const char *title);
  static void Draw(Texture &texture, Shader &shader, glm::vec3 position,
                   glm::vec2 size, GLfloat rotate, glm::vec3 color);
  static void InitBaseSettings();
  static void TerminateRenderer();
  static GLFWwindow *Window;

private:
  static GLuint VAO;
};
}

#endif //RENDERER_H