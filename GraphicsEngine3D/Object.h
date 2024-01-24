#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "ObjectMaterial.h"

/**
 * @brief Klasa bazowa dla wszystkich obiektów 3D w scenie.
 *
 * `Object` jest klas¹ abstrakcyjn¹ s³u¿¹c¹ jako bazowa dla wszystkich obiektów w scenie 3D.
 * Definiuje interfejs do rysowania i pozycjonowania obiektów, a tak¿e zarz¹dzania ich kolorami i materia³ami.
 */
class Object
{
public:
    /**
     * @brief Rysuje obiekt na scenie.
     *
     * Ta metoda musi byæ zaimplementowana w klasach pochodnych, aby okreœliæ,
     * jak obiekt powinien byæ rysowany.
     */
    virtual void draw() const = 0;

    /**
     * @brief Ustawia pozycjê obiektu.
     *
     * @param position Nowa pozycja obiektu jako glm::vec3.
     */
    virtual void setPosition(const glm::vec3& position) = 0;

    /**
     * @brief Pobiera aktualn¹ pozycjê obiektu.
     *
     * @return Aktualna pozycja obiektu jako glm::vec3.
     */
    virtual glm::vec3 getPosition() = 0;

    /**
     * @brief Ustawia kolor obiektu.
     *
     * @param r Sk³adowa czerwona koloru.
     * @param g Sk³adowa zielona koloru.
     * @param b Sk³adowa niebieska koloru.
     * @param a Sk³adowa alfa koloru (przezroczystoœæ).
     */
    void setColor(float r, float g, float b, float a);
protected:
    float color[4] = { 1, 1, 1, 1}; ///< Domyœlny kolor obiektu.

    ObjectMaterial material;        ///< Materia³ obiektu.

    /**
     * @brief Stosuje materia³ na obiekt.
     *
     * Ta metoda jest u¿ywana wewnêtrznie do aplikowania materia³u na obiekt
     * przed jego narysowaniem.
     */
    void applyMaterial() const;
};

