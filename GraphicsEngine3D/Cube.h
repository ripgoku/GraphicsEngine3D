#pragma once

#include <GL/glew.h>
#include "Object.h"
#include "Texture.h"

/**
 * @brief Klasa reprezentuj�ca kostk� 3D w silniku graficznym.
 *
 * Klasa `Cube` dziedziczy po klasie `Object` i jest odpowiedzialna za reprezentacj�
 * kostki 3D. Umo�liwia ustawienie rozmiaru, po�o�enia, rotacji, skalowania oraz tekstury kostki.
 * Zawiera metody do rysowania kostki zar�wno z tekstur� jak i bez.
 */
class Cube : public Object
{
public:
    /**
     * @brief Konstruktor klasy Cube.
     *
     * Inicjalizuje sze�cian o podanym rozmiarze i materiale. Ustawia r�wnie� domy�lne warto�ci
     * transformacji (pozycji, skalowania, obrotu).
     *
     * @param size Rozmiar kraw�dzi sze�cianu.
     * @param type Typ materia�u.
     */
    Cube(float size, Material type);

    /**
     * @brief Rysuje sze�cian w scenie.
     *
     * Przygotowuje transformacje sze�cianu, a nast�pnie rysuje go z zastosowaniem materia�u.
     */
    void draw() const override;

    /**
     * @brief Ustawia now� pozycj� sze�cianu.
     *
     * @param newPosition Nowa pozycja sze�cianu w przestrzeni 3D.
     */
    void setPosition(const glm::vec3& position);

    /**
     * @brief Ustawia obr�t sze�cianu.
     *
     * @param angle K�t obrotu w stopniach.
     * @param axis O� obrotu.
     */
    void setRotation(float angle, const glm::vec3& axis);

    /**
     * @brief Ustawia skalowanie sze�cianu.
     *
     * @param scl Wektor skalowania.
     */
    void setScale(const glm::vec3& scale);

    /**
     * @brief Rysuje sze�cian z tekstur�.
     *
     * Powi�zuje tekstur� z sze�cianem, a nast�pnie rysuje go w scenie.
     *
     * @param texture Tekstura do na�o�enia na sze�cian.
     */
    void drawTexturedCube(const Texture& texture);

    /**
     * @brief Zwraca obecn� pozycj� sze�cianu.
     *
     * @return Pozycja sze�cianu w przestrzeni 3D.
     */
    glm::vec3 getPosition();
private:
    float size;
    glm::vec3 position;
    glm::vec3 scale;
    float rotationAngle;
    glm::vec3 rotationAxis;
};

