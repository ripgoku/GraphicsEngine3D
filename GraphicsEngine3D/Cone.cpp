#include "Cone.h"

Cone::Cone(float base, float height, int slices, int stacks, Material type)
    : base(base), height(height), slices(slices), stacks(stacks), position(0.0f), scale(1.0f), rotationAngle(0.0f), rotationAxis(0.0f, 1.0f, 0.0f) {
    this->material = getMaterial(type);
}

void Cone::draw() const {
    applyMaterial();

    glPushMatrix();

    glTranslatef(position.x, position.y, position.z);
    glRotatef(rotationAngle, rotationAxis.x, rotationAxis.y, rotationAxis.z);
    glScalef(scale.x, scale.y, scale.z);

    glutSolidCone(base, height, slices, stacks);

    glPopMatrix();
}


void Cone::setPosition(const glm::vec3& newPosition) {
    position = newPosition;
}

glm::vec3 Cone::getPosition()
{
    return position;
}

void Cone::setRotation(float angle, const glm::vec3& axis) {
    rotationAngle = angle;
    rotationAxis = axis;
}

void Cone::setScale(const glm::vec3& scl) {
    scale = scl;
}