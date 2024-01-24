#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <algorithm>
#include <iterator>
#include <iostream>
class ObjectMaterial
{
private:
    GLfloat diffuse[4];
    GLfloat ambient[4];
    GLfloat specular[4];
    GLfloat shininess;
    GLfloat emission[4];

public:
    ObjectMaterial(float color[4]);
    ObjectMaterial();
    void setAmbient(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    void setDiffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    void setSpecular(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    void setShininess(GLfloat s);
    void setEmission(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    void apply() const;

    ObjectMaterial& operator=(const ObjectMaterial& other) {
        if (this != &other) {
            std::copy(std::begin(other.ambient), std::end(other.ambient), std::begin(ambient));
            std::copy(std::begin(other.diffuse), std::end(other.diffuse), std::begin(diffuse));
            std::copy(std::begin(other.specular), std::end(other.specular), std::begin(specular));
            std::copy(std::begin(other.emission), std::end(other.emission), std::begin(emission));
            shininess = other.shininess;
        }
        return *this;
    }
};

enum class Material {
    Default,
    Wood,
    Stone,
    Glass,
    Sand,
    Metal,
    Plastic,
    Water
};

ObjectMaterial getMaterial(Material type);