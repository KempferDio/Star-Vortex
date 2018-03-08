#include <Core/ResourceManager.h>

using namespace Core;

std::map<std::string, Shader> ResourceManager::Shaders;
std::map<std::string, Texture> ResourceManager::Textures;

void ResourceManager::LoadShader(const char *vertexPath, const char *fragmentPath, std::string name)
{
    std::string vertexCode = loadShaderFile(vertexPath);
    std::string fragmentCode = loadShaderFile(fragmentPath);
    Shader shader(vertexCode, fragmentCode);

    Shaders.insert(std::map<std::string, Shader>::value_type(name, shader));
}

void ResourceManager::LoadTexture(const char *path, std::string name)
{
    /*Texture texture = loadTextureFromFile(path);
    Textures[name] = texture;*/
    Texture texture = loadTextureFromFile(path);
    Textures.insert(std::map<std::string, Texture>::value_type(name, texture));
}

Shader &ResourceManager::GetShader(const char *name)
{
    
    return Shaders.at(name);
}

Texture &ResourceManager::GetTexture(const char *name)
{
    return Textures.at(name);
}
//Returns string object
std::string ResourceManager::loadShaderFile(const char *path)
{
    std::string shaderCode;

    std::fstream shaderFile;
    shaderFile.exceptions(std::fstream::failbit | std::fstream::badbit);

    try
    {
        shaderFile.open(path);

        std::stringstream shaderStream;

        shaderStream << shaderFile.rdbuf();

        shaderCode = shaderStream.str();

        shaderFile.close();
    }
    catch (std::fstream::failure e)
    {
        std::cerr << e.what() << std::endl;
    }

    return shaderCode;
}

Texture ResourceManager::loadTextureFromFile(const char *path)
{

    Texture texture;
    //Alpha format here
    int width, height, nrChannels;
    unsigned char *image = stbi_load(path, &width, &height, &nrChannels, 0);
    if (image)
    {
        //Generate texture
        texture.Generate(image, width, height);
        Logger::Log("Texture was loaded and created", "loadTextureFromFile");
    }
    else
    {
        Logger::Log("Texture wasn't load", "loadTextureFromFile");
    }
    //Free data
    stbi_image_free(image);
    return texture;
}

void ResourceManager::FreeResources()
{
   /* for (auto shader : Shaders)
    {
        glDeleteProgram(shader.second.Id);
    }

    for (auto texture : Textures)
    {
        glDeleteTextures(1, &texture.second.Id);
    }*/

    for(std::map<std::string, Shader>::iterator it = Shaders.begin(); it != Shaders.end(); it++) {
        glDeleteProgram(it->second.Id);
    }

    for(std::map<std::string, Texture>::iterator it = Textures.begin(); it != Textures.end(); it++) {
        glDeleteTextures(1, &it->second.Id);
    }
}