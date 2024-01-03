#pragma once

#include "IndexedCube.h"
#include "TransformableObject.h"
#include <glm/gtc/matrix_transform.hpp>

class TransformableCube : public IndexedCube, public TransformableObject {
public:
    TransformableCube(float size);

    void translate(const glm::vec3& translation) override;
    void rotate(float angle, const glm::vec3& axis) override;
    void scale(const glm::vec3& scale) override;
};
