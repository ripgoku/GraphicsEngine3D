#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "ObjectMaterial.h"

class Object
{
public:
    virtual void draw() const = 0;
    virtual void setPosition(const glm::vec3& position) = 0;
    virtual glm::vec3 getPosition() = 0;

    void setColor(float r, float g, float b, float a);
protected:
    float color[4] = { 1, 1, 1, 1};

    ObjectMaterial material;
    void applyMaterial() const;
};

