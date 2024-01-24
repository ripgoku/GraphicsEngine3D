#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <algorithm>
#include <iterator>
#include <iostream>

/**
 * @brief Klasa reprezentuj�ca materia� obiektu 3D.
 *
 * `ObjectMaterial` odpowiada za przechowywanie w�a�ciwo�ci materia��w, takich jak kolor rozproszony (diffuse),
 * odbicie otoczenia (ambient), odbicie lustrzane (specular), po�ysk i emisja �wiat�a. Pozwala na
 * zastosowanie tych w�a�ciwo�ci do obiekt�w 3D w scenie.
 */
class ObjectMaterial
{
private:
    GLfloat diffuse[4];   ///< Kolor rozproszony materia�u.
    GLfloat ambient[4];   ///< Odbicie otoczenia materia�u.
    GLfloat specular[4];  ///< Odbicie lustrzane materia�u.
    GLfloat shininess;    ///< Po�ysk materia�u.
    GLfloat emission[4];  ///< Emisja �wiat�a przez materia�.

public:
    /**
     * @brief Konstruktor domy�lny, inicjuj�cy materia� z domy�lnymi warto�ciami.
     */
    ObjectMaterial();

    /**
     * @brief Ustawia kolor odbicia otoczenia materia�u.
     *
     * @param r Sk�adowa czerwona koloru.
     * @param g Sk�adowa zielona koloru.
     * @param b Sk�adowa niebieska koloru.
     * @param a Sk�adowa alfa koloru (przezroczysto��).
     */
    void setAmbient(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    /**
     * @brief Ustawia kolor rozproszony materia�u.
     *
     * @param r Sk�adowa czerwona koloru.
     * @param g Sk�adowa zielona koloru.
     * @param b Sk�adowa niebieska koloru.
     * @param a Sk�adowa alfa koloru (przezroczysto��).
     */
    void setDiffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    /**
     * @brief Ustawia kolor odbicia lustrzanego materia�u.
     *
     * @param r Sk�adowa czerwona koloru.
     * @param g Sk�adowa zielona koloru.
     * @param b Sk�adowa niebieska koloru.
     * @param a Sk�adowa alfa koloru (przezroczysto��).
     */
    void setSpecular(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    /**
     * @brief Ustawia po�ysk materia�u.
     *
     * @param s Poziom po�ysku.
     */
    void setShininess(GLfloat s);

    /**
     * @brief Ustawia kolor emisji �wiat�a.
     *
     * @param r Sk�adowa czerwona koloru.
     * @param g Sk�adowa zielona koloru.
     * @param b Sk�adowa niebieska koloru.
     * @param a Sk�adowa alfa koloru (przezroczysto��).
     */
    void setEmission(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    /**
     * @brief Stosuje w�a�ciwo�ci materia�u na aktualnie rysowany obiekt.
     *
     * Ta metoda konfiguruje OpenGL do u�ywania zdefiniowanych w�a�ciwo�ci materia�u
     * dla aktualnie rysowanego obiektu.
     */
    void apply() const;

    /**
     * @brief Operator przypisania.
     *
     * Pozwala na przypisanie warto�ci z jednego obiektu ObjectMaterial do drugiego.
     * @param other Inny obiekt ObjectMaterial, z kt�rego warto�ci b�d� skopiowane.
     * @return Referencja do *this.
     */
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

/**
 * @brief Funkcja pomocnicza do pobierania predefiniowanych materia��w.
 *
 * @param type Typ materia�u zdefiniowany w enumeracji `Material`.
 * @return Obiekt `ObjectMaterial` z w�a�ciwo�ciami odpowiadaj�cymi wybranemu typowi.
 */
ObjectMaterial getMaterial(Material type);