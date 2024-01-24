#pragma once

#include <GL/glew.h>
#include "Object.h"
#include "Texture.h"

class Cube : public Object
{
public:
    Cube(float size, Material type);
    void draw() const override;
    void setPosition(const glm::vec3& position);
    void setRotation(float angle, const glm::vec3& axis);
    void setScale(const glm::vec3& scale);
    void drawTexturedCube(const Texture& texture);
    glm::vec3 getPosition();
private:
    float size;
    glm::vec3 position;
    glm::vec3 scale;
    float rotationAngle;
    glm::vec3 rotationAxis;
};

