#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform
{
public:
    glm::mat4 transformMatrix;

    Transform()
    {
        this->transformMatrix = glm::mat4(1.0f);
        this->scaling = glm::vec3(1.0f, 1.0f, 1.0f);
        this->rotation = glm::vec3(.0f, .0f, .0f);
        this->position = glm::vec3(.0f, .0f, .0f);
    }

    Transform(glm::mat4 transformMatrix, glm::vec3 position, glm::vec3  rotation, glm::vec3 scaling);

    void Translate(glm::vec3 position);
    void Scale(glm::vec3 scaling);

    glm::vec3 getPosition();
    glm::vec3 setPosition(glm::vec3 newPosition);

    glm::vec3 Scaling();

private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scaling;

};

