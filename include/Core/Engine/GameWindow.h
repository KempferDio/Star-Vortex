#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <GLFW/glfw3.h>

typedef struct GameWindow
{
    unsigned int Width;
    unsigned int Height;
    const char *Title;
    GLFWwindow *WindowPtr;
} GameWindow;

#endif