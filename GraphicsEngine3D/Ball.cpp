#include "Ball.h"

Ball::Ball(float radius, int slices, int stacks, Material type)
    : radius(radius), slices(slices), stacks(stacks), position(0.0f), scale(1.0f), rotationAngle(0.0f), rotationAxis(0.0f, 1.0f, 0.0f) {
    this->material = getMaterial(type);
}

void Ball::draw() const {
    applyMaterial();

    glPushMatrix(); // Zapisuje obecn� macierz

    // Zastosuj transformacje
    glTranslatef(position.x, position.y, position.z);
    glRotatef(rotationAngle, rotationAxis.x, rotationAxis.y, rotationAxis.z);
    glScalef(scale.x, scale.y, scale.z);

    // Rysuj kostk�
    glutSolidSphere(radius, slices, stacks);

    glPopMatrix(); // Przywraca poprzedni� macierz
}


void Ball::setPosition(const glm::vec3& newPosition) {
    position = newPosition;
}

glm::vec3 Ball::getPosition()
{
    return position;
}

void Ball::setRotation(float angle, const glm::vec3& axis) {
    rotationAngle = angle;
    rotationAxis = axis;
}

void Ball::setScale(const glm::vec3& scl) {
    scale = scl;
}

void Ball::drawTexturedBall(const Texture& texture) {
    texture.bind(); // Powi�zanie tekstury
    glEnable(GL_TEXTURE_2D); // W��czenie obs�ugi tekstur

    glPushMatrix(); // Zapisuje obecn� macierz

    // Zastosuj transformacje
    glTranslatef(position.x, position.y, position.z);
    glRotatef(rotationAngle, rotationAxis.x, rotationAxis.y, rotationAxis.z);
    glScalef(scale.x, scale.y, scale.z);

    // Rysuj sfere
    GLUquadric* quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE);
    gluSphere(quadric, radius, slices, stacks);
    gluDeleteQuadric(quadric);

    glPopMatrix(); // Przywraca poprzedni� macierz

    glDisable(GL_TEXTURE_2D); // Wy��czenie obs�ugi tekstur
}