#include "Transform.h"


Transform::Transform(glm::mat4  transformMatrix, glm::vec3  position, glm::vec3  rotation, glm::vec3  scaling)
{
    this->transformMatrix = transformMatrix;
    this->position = position;
    this->scaling = scaling;
    this->rotation = rotation;

    this->Translate(position);
    this->Scale(scaling);
}

void Transform::Translate(glm::vec3 position)
{
    this->position = position;
    this->transformMatrix = glm::translate(this->transformMatrix, position);
}

glm::vec3 Transform::getPosition()
{
    return this->position;
}

glm::vec3 Transform::setPosition(glm::vec3 newPosition)
{
    transformMatrix = glm::translate(glm::mat4(1), position);
    this->position = newPosition;
    return this->position;
}

void Transform::Scale(glm::vec3 scaling)
{
    this->scaling = scaling;
    this->transformMatrix = glm::scale(this->transformMatrix, scaling);
}

glm::vec3 Transform::Scaling()
{
    return this->scaling;
}


