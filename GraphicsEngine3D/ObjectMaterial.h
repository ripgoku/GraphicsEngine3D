#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <algorithm>
#include <iterator>
#include <iostream>
class ObjectMaterial
{
private:
    //GLfloat ambient[4];   // Kolor bez œwiat³a
    GLfloat diffuse[4];   // Kolor oœwietlony
    GLfloat ambient[4];   // Kolor bez œwiat³a
    GLfloat specular[4];  // Kolor po³ysku
    GLfloat shininess;    // Stopieñ po³ysku
    GLfloat emission[4];  // Kolor emisii

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
        if (this != &other) { // Ochrona przed samoprzypisaniem
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