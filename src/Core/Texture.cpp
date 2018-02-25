#include <Core/Common/Texture.h>

using namespace Core;

Texture::Texture()
{
    //Default ctor
    //For map in resource manager
}

void Texture::Generate(unsigned char *image, int width, int height)
{
    glGenTextures(1, &Id);
    glBindTexture(GL_TEXTURE_2D, Id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
}

void Texture::Bind()
{
}