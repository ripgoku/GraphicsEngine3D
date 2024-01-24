#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "ObjectMaterial.h"

/**
 * @brief Klasa bazowa dla wszystkich obiekt�w 3D w scenie.
 *
 * `Object` jest klas� abstrakcyjn� s�u��c� jako bazowa dla wszystkich obiekt�w w scenie 3D.
 * Definiuje interfejs do rysowania i pozycjonowania obiekt�w, a tak�e zarz�dzania ich kolorami i materia�ami.
 */
class Object
{
public:
    /**
     * @brief Rysuje obiekt na scenie.
     *
     * Ta metoda musi by� zaimplementowana w klasach pochodnych, aby okre�li�,
     * jak obiekt powinien by� rysowany.
     */
    virtual void draw() const = 0;

    /**
     * @brief Ustawia pozycj� obiektu.
     *
     * @param position Nowa pozycja obiektu jako glm::vec3.
     */
    virtual void setPosition(const glm::vec3& position) = 0;

    /**
     * @brief Pobiera aktualn� pozycj� obiektu.
     *
     * @return Aktualna pozycja obiektu jako glm::vec3.
     */
    virtual glm::vec3 getPosition() = 0;

    /**
     * @brief Ustawia kolor obiektu.
     *
     * @param r Sk�adowa czerwona koloru.
     * @param g Sk�adowa zielona koloru.
     * @param b Sk�adowa niebieska koloru.
     * @param a Sk�adowa alfa koloru (przezroczysto��).
     */
    void setColor(float r, float g, float b, float a);
protected:
    float color[4] = { 1, 1, 1, 1}; ///< Domy�lny kolor obiektu.

    ObjectMaterial material;        ///< Materia� obiektu.

    /**
     * @brief Stosuje materia� na obiekt.
     *
     * Ta metoda jest u�ywana wewn�trznie do aplikowania materia�u na obiekt
     * przed jego narysowaniem.
     */
    void applyMaterial() const;
};

