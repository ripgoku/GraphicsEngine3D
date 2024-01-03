#pragma once

#include <glm/vec3.hpp>
#include <glm/gtx/norm.hpp>
#include <GL/freeglut.h>
#include <vector>

class IndexedCube {
public:
    IndexedCube(float size);

    void calculateNormals();
    void draw(float r, float g, float b);

    std::vector<float> vertices;

private:
    float sideLength;
    std::vector<unsigned int> indices;
    std::vector<float> colors;
    std::vector<float> normals;
};
