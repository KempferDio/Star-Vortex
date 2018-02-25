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

  void Bind() const;
  void Generate(unsigned char *image, GLuint width, GLuint height);

  GLuint Id;
  GLuint Width, Height;
  GLuint internalFormat;
  GLuint imageFormat;
  GLuint wrapS;
  GLuint wrapT;
  GLuint filterMin;
  GLuint filterMax;
};
}

#endif //TEXTURE_H