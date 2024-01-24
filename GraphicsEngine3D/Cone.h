#pragma once

#include <GL/glew.h>
#include "Object.h"

class Cone : public Object
{
public:
    Cone(float base, float height, int slices, int stacks, Material type);
    void draw() const override;
    void setPosition(const glm::vec3& position) override;
    void setRotation(float angle, const glm::vec3& axis);
    void setScale(const glm::vec3& scale);
    glm::vec3 getPosition();
private:
    float base, height, slices, stacks;
    glm::vec3 position;
    glm::vec3 scale;
    float rotationAngle;
    glm::vec3 rotationAxis;
};

