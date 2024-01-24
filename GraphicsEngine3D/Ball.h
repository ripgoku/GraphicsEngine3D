#pragma once

#include <GL/glew.h>
#include "Object.h"
#include "Texture.h"

class Ball : public Object
{
public:
    Ball(float radius, int slices, int stacks, Material type);
    void draw() const override;
    void setPosition(const glm::vec3& position) override;
    void setRotation(float angle, const glm::vec3& axis);
    void setScale(const glm::vec3& scale);
    void drawTexturedBall(const Texture& texture);
    glm::vec3 getPosition();
private:
    float radius, slices, stacks;
    glm::vec3 position;
    glm::vec3 scale;
    float rotationAngle;
    glm::vec3 rotationAxis;
};

