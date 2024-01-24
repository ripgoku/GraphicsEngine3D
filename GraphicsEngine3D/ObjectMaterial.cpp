#include "objectMaterial.h"
ObjectMaterial::ObjectMaterial() {
    setAmbient(0.2f, 0.2f, 0.2f, 1.0f);
    setDiffuse(0.8f, 0.8f, 0.8f, 1.0f);
    setSpecular(0.0f, 0.0f, 0.0f, 1.0f);
    setShininess(0.0f);
    setEmission(0.0f, 0.0f, 0.0f, 1.0f);
}

void ObjectMaterial::setAmbient(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    ambient[0] = r;
    ambient[1] = g;
    ambient[2] = b;
    ambient[3] = a;
}

void ObjectMaterial::setDiffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    diffuse[0] = r;
    diffuse[1] = g;
    diffuse[2] = b;
    diffuse[3] = a;
}

void ObjectMaterial::setSpecular(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    specular[0] = r;
    specular[1] = g;
    specular[2] = b;
    specular[3] = a;
}

void ObjectMaterial::setShininess(GLfloat s) {
    shininess = s;
}

void ObjectMaterial::setEmission(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    emission[0] = r;
    emission[1] = g;
    emission[2] = b;
    emission[3] = a;
}

void ObjectMaterial::apply() const {
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}

ObjectMaterial getMaterial(Material type)
{
    ObjectMaterial material;
    switch (type)
    {
    case Material::Default:
        material.setAmbient(0.5f, 0.5f, 0.5f, 1.0f);
        material.setDiffuse(0.5f, 0.5f, 0.5f, 1.0f);
        material.setSpecular(0.5f, 0.5f, 0.5f, 1.0f);
        material.setShininess(30.0f);
        break;
    case Material::Wood:
        material.setAmbient(0.4f, 0.3f, 0.2f, 1.0f);
        material.setDiffuse(0.6f, 0.5f, 0.4f, 1.0f);
        material.setSpecular(0.1f, 0.1f, 0.1f, 1.0f);
        material.setShininess(30.0f);
        break;
    case Material::Stone:
        material.setAmbient(0.3f, 0.3f, 0.3f, 1.0f);
        material.setDiffuse(0.5f, 0.5f, 0.5f, 1.0f);
        material.setSpecular(0.1f, 0.1f, 0.1f, 1.0f);
        material.setShininess(10.0f);
        break;
    case Material::Glass:
        material.setAmbient(0.1f, 0.2f, 0.3f, 0.3f);
        material.setDiffuse(0.6f, 0.7f, 0.8f, 0.3f);
        material.setSpecular(0.9f, 0.9f, 1.0f, 1.0f);
        material.setShininess(100.0f);
        break;
    case Material::Sand:
        material.setAmbient(0.5f, 0.4f, 0.3f, 1.0f);
        material.setDiffuse(0.7f, 0.6f, 0.5f, 1.0f);
        material.setSpecular(0.05f, 0.05f, 0.05f, 1.0f);
        material.setShininess(5.0f);
        break;
    case Material::Metal:
        material.setAmbient(0.3f, 0.3f, 0.3f, 1.0f);
        material.setDiffuse(0.7f, 0.7f, 0.7f, 1.0f);
        material.setSpecular(0.8f, 0.8f, 0.8f, 1.0f);
        material.setShininess(80.0f);
        break;
    case Material::Plastic:
        material.setAmbient(0.3f, 0.3f, 0.3f, 1.0f);
        material.setDiffuse(0.6f, 0.6f, 0.6f, 1.0f);
        material.setSpecular(0.5f, 0.5f, 0.5f, 1.0f);
        material.setShininess(60.0f);
        break;
    case Material::Water:
        material.setAmbient(0.0f, 0.1f, 0.2f, 0.8f);
        material.setDiffuse(0.0f, 0.5f, 0.8f, 0.8f);
        material.setSpecular(0.8f, 0.8f, 1.0f, 1.0f);
        material.setShininess(100.0f);
        break;
    default:
        break;
    }
    return material;
}