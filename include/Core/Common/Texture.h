#ifndef TEXTURE_H
#define TEXTURE_H
#include <glad/glad.h>

/*
  Base texture

  TODO: Full texture settings
*/

namespace Core
{
class Texture
{
public:
  Texture();
  void Bind();
  void Generate(unsigned char *image, int width, int height);

  GLuint Id;

private:
  unsigned char loadTextureFromFile(const char *path);
};
}

#endif //TEXTURE_H