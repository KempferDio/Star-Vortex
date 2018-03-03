#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Core/Texture.h>
#include <Core/Shader.h>
#include <Core/GameWindow.h>
#include <Core/ResourceManager.h>

namespace Core
{
class Renderer
{
public:
  //
  Renderer(unsigned int width, unsigned int height, const char *title);
  ~Renderer();
  void ClearScreen();
  void Draw(const char *textureName, const char *shaderName, glm::vec2 position,
            glm::vec2 size, GLfloat rotate, glm::vec3 color);
  void InitBaseSettings();
  void TerminateRenderer();
  GLFWwindow *GetWindow();
  GameWindow Window;

  //Test function
  void printMatrix(glm::mat4 mat)
  {
    std::cout << "=====================================" << std::endl;
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        std::cout << mat[i][j] << " ";
      }

      std::cout << "\n";
    }
    std::cout << "=====================================" << std::endl;
  }

private:
  GLuint VAO;
};
}

#endif //RENDERER_H