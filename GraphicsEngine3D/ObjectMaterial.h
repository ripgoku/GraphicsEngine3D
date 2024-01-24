#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <algorithm>
#include <iterator>
#include <iostream>

/**
 * @brief Klasa reprezentuj¹ca materia³ obiektu 3D.
 *
 * `ObjectMaterial` odpowiada za przechowywanie w³aœciwoœci materia³ów, takich jak kolor rozproszony (diffuse),
 * odbicie otoczenia (ambient), odbicie lustrzane (specular), po³ysk i emisja œwiat³a. Pozwala na
 * zastosowanie tych w³aœciwoœci do obiektów 3D w scenie.
 */
class ObjectMaterial
{
private:
    GLfloat diffuse[4];   ///< Kolor rozproszony materia³u.
    GLfloat ambient[4];   ///< Odbicie otoczenia materia³u.
    GLfloat specular[4];  ///< Odbicie lustrzane materia³u.
    GLfloat shininess;    ///< Po³ysk materia³u.
    GLfloat emission[4];  ///< Emisja œwiat³a przez materia³.

public:
    /**
     * @brief Konstruktor domyœlny, inicjuj¹cy materia³ z domyœlnymi wartoœciami.
     */
    ObjectMaterial();

    /**
     * @brief Ustawia kolor odbicia otoczenia materia³u.
     *
     * @param r Sk³adowa czerwona koloru.
     * @param g Sk³adowa zielona koloru.
     * @param b Sk³adowa niebieska koloru.
     * @param a Sk³adowa alfa koloru (przezroczystoœæ).
     */
    void setAmbient(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    /**
     * @brief Ustawia kolor rozproszony materia³u.
     *
     * @param r Sk³adowa czerwona koloru.
     * @param g Sk³adowa zielona koloru.
     * @param b Sk³adowa niebieska koloru.
     * @param a Sk³adowa alfa koloru (przezroczystoœæ).
     */
    void setDiffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    /**
     * @brief Ustawia kolor odbicia lustrzanego materia³u.
     *
     * @param r Sk³adowa czerwona koloru.
     * @param g Sk³adowa zielona koloru.
     * @param b Sk³adowa niebieska koloru.
     * @param a Sk³adowa alfa koloru (przezroczystoœæ).
     */
    void setSpecular(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    /**
     * @brief Ustawia po³ysk materia³u.
     *
     * @param s Poziom po³ysku.
     */
    void setShininess(GLfloat s);

    /**
     * @brief Ustawia kolor emisji œwiat³a.
     *
     * @param r Sk³adowa czerwona koloru.
     * @param g Sk³adowa zielona koloru.
     * @param b Sk³adowa niebieska koloru.
     * @param a Sk³adowa alfa koloru (przezroczystoœæ).
     */
    void setEmission(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    /**
     * @brief Stosuje w³aœciwoœci materia³u na aktualnie rysowany obiekt.
     *
     * Ta metoda konfiguruje OpenGL do u¿ywania zdefiniowanych w³aœciwoœci materia³u
     * dla aktualnie rysowanego obiektu.
     */
    void apply() const;

    /**
     * @brief Operator przypisania.
     *
     * Pozwala na przypisanie wartoœci z jednego obiektu ObjectMaterial do drugiego.
     * @param other Inny obiekt ObjectMaterial, z którego wartoœci bêd¹ skopiowane.
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
 * @brief Funkcja pomocnicza do pobierania predefiniowanych materia³ów.
 *
 * @param type Typ materia³u zdefiniowany w enumeracji `Material`.
 * @return Obiekt `ObjectMaterial` z w³aœciwoœciami odpowiadaj¹cymi wybranemu typowi.
 */
ObjectMaterial getMaterial(Material type);