#ifndef TEXTURE_H
#define TEXTURE_H
#include <glad/glad.h>

/*
    Base texture
*/

namespace Core
{
class Texture
{
public:
  Texture(); //Base texture settings
  void Bind();

private:
  GLuint id;
  unsigned char loadTextureFromFile(const char *path);
};
}

#endif //TEXTURE_H