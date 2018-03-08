#include <Core/Camera.h>

using namespace Core;

Camera::Camera() 
: position(glm::vec3(0.0f, 0.0f, 0.0f)),
 forward(glm::vec3(0.0f, 0.0f, -1.0f)),
 up(glm::vec3(0.0f, 1.0f, 0.0f))
{
    Logger::Log("Camera was created", "Camera::Camera()");
}

Camera::Camera(glm::vec3 pos, glm::vec3 up, glm::vec3 forward) {
    this->position = pos;
    this->up = up;
    this->forward = forward;
}

glm::mat4 Camera::getViewMatrix() {
    return glm::lookAt(position, position + forward, up);
}