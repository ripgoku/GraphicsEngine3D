#include "TransformableCube.h"

TransformableCube::TransformableCube(float size) : IndexedCube(size) {}

void TransformableCube::translate(const glm::vec3& translation) {
    for (size_t i = 0; i < vertices.size(); i += 3) {
        vertices[i] += translation.x;
        vertices[i + 1] += translation.y;
        vertices[i + 2] += translation.z;
    }

    calculateNormals();
}

void TransformableCube::rotate(float angle, const glm::vec3& axis) {
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(angle), axis);

    for (size_t i = 0; i < vertices.size(); i += 3) {
        glm::vec4 vertex = glm::vec4(vertices[i], vertices[i + 1], vertices[i + 2], 1.0f);
        vertex = rotationMatrix * vertex;
        vertices[i] = vertex.x;
        vertices[i + 1] = vertex.y;
        vertices[i + 2] = vertex.z;
    }

    calculateNormals();
}

void TransformableCube::scale(const glm::vec3& scale) {
    for (size_t i = 0; i < vertices.size(); i += 3) {
        vertices[i] *= scale.x;
        vertices[i + 1] *= scale.y;
        vertices[i + 2] *= scale.z;
    }

    calculateNormals();
}
