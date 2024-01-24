#include "Object.h"

void Object::setColor(float r, float g, float b, float a) {
    this->color[0] = r;
    this->color[1] = g;
    this->color[2] = b;
    this->color[3] = a;
}

void Object::applyMaterial() const {
    glDisable(GL_LIGHTING);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
    this->material.apply();
    glEnable(GL_LIGHTING);
}