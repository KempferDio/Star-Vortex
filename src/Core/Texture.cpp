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

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    //glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Bind() const
{
    glBindTexture(GL_TEXTURE_2D, Id);
}