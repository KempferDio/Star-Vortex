#include <Core/Engine/ResourceManager.h>

using namespace Core;

std::map<std::string, Shader> ResourceManager::Shaders;
std::map<std::string, Texture> ResourceManager::Textures;

void ResourceManager::LoadShader(const char *vertexPath, const char *fragmentPath, std::string name)
{
    std::string vertexCode = loadShaderFile(vertexPath);
    std::string fragmentCode = loadShaderFile(fragmentPath);

    Shaders.insert(std::map<std::string, Shader>::value_type(name, Shader(vertexCode, fragmentCode)));
}

void ResourceManager::LoadTexture(const char *path, std::string name)
{
    /*Texture texture = loadTextureFromFile(path);
    Textures[name] = texture;*/

    Textures.insert(std::map<std::string, Texture>::value_type(name, Texture()));
}

Shader ResourceManager::GetShader(const char *name)
{
    return Shaders[name];
}

Texture ResourceManager::GetTexture(const char *name)
{
    return Textures[name];
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

//Later
Texture ResourceManager::loadTextureFromFile(const char *path)
{

    Texture texture;
    //Alpha format here
    int width, height;
    unsigned char *image = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGB);
    if (image)
    {
        //Generate texture
        texture.Generate(image, width, height);
    }
    //Free data
    SOIL_free_image_data(image);
    return texture;
}

void ResourceManager::FreeResources()
{
    for (auto shader : Shaders)
    {
        glDeleteProgram(shader.second.Id);
    }

    for (auto texture : Textures)
    {
        glDeleteTextures(1, &texture.second.Id);
    }
}