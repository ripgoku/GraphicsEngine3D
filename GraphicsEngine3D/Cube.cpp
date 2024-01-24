#include "Cube.h"

Cube::Cube(float size, Material type)
    : size(size), position(0.0f), scale(1.0f), rotationAngle(0.0f), rotationAxis(0.0f, 1.0f, 0.0f) {
    this->material = getMaterial(type);
}

void Cube::draw() const {
    applyMaterial();

    glPushMatrix(); // Zapisuje obecn¹ macierz

    // Zastosuj transformacje
    glTranslatef(position.x, position.y, position.z);
    glRotatef(rotationAngle, rotationAxis.x, rotationAxis.y, rotationAxis.z);
    glScalef(scale.x, scale.y, scale.z);

    // Rysuj kostkê
    glutSolidCube(size);

    glPopMatrix(); // Przywraca poprzedni¹ macierz
}


void Cube::setPosition(const glm::vec3& newPosition) {
    position = newPosition;
}

glm::vec3 Cube::getPosition()
{
    return position;
}

void Cube::setRotation(float angle, const glm::vec3& axis) {
    rotationAngle = angle;
    rotationAxis = axis;
}

void Cube::setScale(const glm::vec3& scl) {
    scale = scl;
}

void Cube::drawTexturedCube(const Texture& texture) {
    // Bind the texture
    texture.bind();
    applyMaterial();

    glPushMatrix(); // Zapisuje obecn¹ macierz

    // Zastosuj transformacje
    glTranslatef(position.x, position.y, position.z);
    glRotatef(rotationAngle, rotationAxis.x, rotationAxis.y, rotationAxis.z);
    glScalef(scale.x, scale.y, scale.z);

    // Enable the capability to use textures
    glEnable(GL_TEXTURE_2D);

    // Start drawing the cube
    glBegin(GL_QUADS);

    // Front Face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-size / 2, -size / 2, size / 2);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(size / 2, -size / 2, size / 2);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(size / 2, size / 2, size / 2);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-size / 2, size / 2, size / 2);

    // Back Face
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-size / 2, -size / 2, -size / 2);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-size / 2, size / 2, -size / 2);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(size / 2, size / 2, -size / 2);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(size / 2, -size / 2, -size / 2);

    // Top Face
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-size / 2, size / 2, -size / 2);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-size / 2, size / 2, size / 2);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(size / 2, size / 2, size / 2);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(size / 2, size / 2, -size / 2);

    // Bottom Face
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-size / 2, -size / 2, -size / 2);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(size / 2, -size / 2, -size / 2);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(size / 2, -size / 2, size / 2);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-size / 2, -size / 2, size / 2);

    // Right face
    glTexCoord2f(1.0f, 0.0f); glVertex3f(size / 2, -size / 2, -size / 2);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(size / 2, size / 2, -size / 2);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(size / 2, size / 2, size / 2);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(size / 2, -size / 2, size / 2);

    // Left Face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-size / 2, -size / 2, -size / 2);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-size / 2, -size / 2, size / 2);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-size / 2, size / 2, size / 2);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-size / 2, size / 2, -size / 2);

    glEnd();

    // Disable the capability to use textures
    glDisable(GL_TEXTURE_2D);
    glPopMatrix(); // Przywraca poprzedni¹ macierz
}

