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
    Texture();
    void Bind();

  private:
    GLuint id;
    unsigned char loadTextureFromFile(const char *path);
};
}

#endif //TEXTURE_H