#include "PrimitiveDrawer.h"

void PrimitiveDrawer::drawPoint(float x, float y, float z, float size, float r, float g, float b) {
    glColor3f(r, g, b);
    glPointSize(size);
    glBegin(GL_POINTS);
    glVertex3f(x, y, z);
    glEnd();
}

void PrimitiveDrawer::drawLine(float x1, float y1, float z1, float x2, float y2, float z2, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_LINES);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glEnd();
}

void PrimitiveDrawer::drawTriangle(float x1, float y1, float z1, float x2, float y2, float z2,
    float x3, float y3, float z3, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);
    glEnd();
}
// Implementuj inne prymitywy w tym pliku wed³ug potrzeb
