#pragma once
#include <GL/freeglut.h>

class GeometryDrawer {
public:
    static void drawCube(float size);
    static void drawFilledCube(float size);
    static void drawSphere(float radius, int slices, int stacks);
    static void drawCone(float base, float height, int slices, int stacks);

    // Dodaj wi�cej metod do rysowania innych obiekt�w geometrycznych wed�ug potrzeb

    static void drawAxes(float length);
};