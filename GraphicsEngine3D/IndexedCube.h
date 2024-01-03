#pragma once
#include <GL/freeglut.h>
#include <vector>

class IndexedCube {
public:
    IndexedCube(float size);
    void draw(float r, float g, float b);

private:
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    std::vector<float> normals;
    std::vector<float> colors;
    float sideLength;

    void calculateNormals();
};
