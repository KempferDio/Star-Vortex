#include <Core/Texture.h>

using namespace Core;

Texture::Texture()
    : Width(0), Height(0), internalFormat(GL_RGB), imageFormat(GL_RGB),
      wrapS(GL_REPEAT), wrapT(GL_REPEAT), filterMin(GL_LINEAR), filterMax(GL_LINEAR)
{
    //Default ctor
    //For map in resource manager
    glGenTextures(1, &Id);
}

void Texture::Generate(unsigned char *image, GLuint width, GLuint height)
{
    this->Width = width;
    this->Height = height;
    glBindTexture(GL_TEXTURE_2D, Id);

    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, imageFormat, GL_UNSIGNED_BYTE, image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filterMin);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filterMax);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Bind() const
{
    glBindTexture(GL_TEXTURE_2D, Id);
}