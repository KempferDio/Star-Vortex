#ifndef CAMERA_H
#define CAMERA_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Core/Logger.h>

namespace Core {
    class Camera {
    public:
        Camera();
        //Camera(/*Actor goes here*/);
        Camera(glm::vec3 pos, glm::vec3 up, glm::vec3 forward);
        glm::vec3 position;
        glm::vec3 forward;
        glm::vec3 up;

        glm::mat4 getViewMatrix();

        //In future
        //Actor target;
    private:
    };
}

#endif