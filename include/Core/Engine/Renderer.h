#ifndef RENDERER_H
#define RENDERER_H
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace Core
{
class Renderer
{
public:
  //
  static void Draw();

private:
  GLFWwindow *window;
};
}

#endif //REDERER_H