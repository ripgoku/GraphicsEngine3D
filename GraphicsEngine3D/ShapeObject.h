#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"

class ShapeObject : public DrawableObject, public TransformableObject {
public:
    virtual ~ShapeObject() {}

    virtual void draw() const = 0;
    virtual void translate(const glm::vec3& translation) = 0;
    virtual void rotate(float angle, const glm::vec3& axis) = 0;
    virtual void scale(const glm::vec3& scale) = 0;
};
