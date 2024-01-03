#include "GeometryDrawer.h"

void GeometryDrawer::drawCube(float size) {
    glutWireCube(size);
}

void GeometryDrawer::drawFilledCube(float size) {
    glutSolidCube(size);
}

void GeometryDrawer::drawSphere(float radius, int slices, int stacks) {
    glutWireSphere(radius, slices, stacks);
}

void GeometryDrawer::drawCone(float base, float height, int slices, int stacks) {
    glutWireCone(base, height, slices, stacks);
}

void GeometryDrawer::drawAxes(float length) {
    glBegin(GL_LINES);
    // O� X - Czerwona
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(length, 0.0f, 0.0f);
    // O� Y - Zielona
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, length, 0.0f);
    // O� Z - Niebieska
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, length);
    glEnd();
}