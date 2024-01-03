#pragma once
#include <GL/freeglut.h>

class PrimitiveDrawer {
public:
    static void drawPoint(float x, float y, float z, float size, float r, float g, float b);
    static void drawLine(float x1, float y1, float z1, float x2, float y2, float z2, float r, float g, float b);
    static void drawTriangle(float x1, float y1, float z1, float x2, float y2, float z2,
        float x3, float y3, float z3, float r, float g, float b);
    // Dodaj inne prymitywy wed³ug potrzeb
};
