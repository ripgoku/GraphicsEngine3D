#pragma once
#include <glm/glm.hpp>

class TransformableObject {
public:
    virtual ~TransformableObject() {}

    virtual void translate(const glm::vec3& translation) = 0;
    virtual void rotate(float angle, const glm::vec3& axis) = 0;
    virtual void scale(const glm::vec3& scale) = 0;
};
