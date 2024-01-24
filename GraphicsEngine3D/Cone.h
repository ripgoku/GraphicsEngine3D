#pragma once

#include <GL/glew.h>
#include "Object.h"

/**
 * @brief Klasa reprezentuj�ca sto�ek 3D w silniku graficznym.
 *
 * Klasa `Cone` dziedziczy po klasie `Object` i jest odpowiedzialna za reprezentacj�
 * sto�ka 3D. Pozwala na ustawienie podstawowych parametr�w geometrycznych sto�ka,
 * takich jak wymiary podstawy i wysoko�ci, liczby wycink�w i stos�w oraz materia�u.
 * Umo�liwia tak�e manipulacj� po�o�eniem, rotacj� i skalowaniem sto�ka.
 */
class Cone : public Object
{
public:
    /**
     * @brief Konstruktor klasy Cone.
     *
     * Inicjalizuje sto�ek z podanymi parametrami: baz�, wysoko�ci�, liczb� wycink�w i stos�w,
     * oraz materia�em. Ustawia r�wnie� domy�lne warto�ci transformacji (pozycji, skalowania, obrotu).
     *
     * @param base Promie� podstawy sto�ka.
     * @param height Wysoko�� sto�ka.
     * @param slices Liczba wycink�w wok� osi Y.
     * @param stacks Liczba stos�w wzd�u� osi Y.
     * @param type Typ materia�u.
     */
    Cone(float base, float height, int slices, int stacks, Material type);

    /**
     * @brief Rysuje sto�ek w scenie.
     *
     * Przygotowuje transformacje sto�ka, a nast�pnie rysuje go z zastosowaniem materia�u.
     */
    void draw() const override;

    /**
     * @brief Ustawia now� pozycj� sto�ka.
     *
     * @param newPosition Nowa pozycja sto�ka w przestrzeni 3D.
     */
    void setPosition(const glm::vec3& position) override;

    /**
     * @brief Ustawia obr�t sto�ka.
     *
     * @param angle K�t obrotu w stopniach.
     * @param axis O� obrotu.
     */
    void setRotation(float angle, const glm::vec3& axis);

    /**
     * @brief Ustawia skalowanie sto�ka.
     *
     * @param scl Wektor skalowania.
     */
    void setScale(const glm::vec3& scale);

    /**
     * @brief Zwraca obecn� pozycj� sto�ka.
     *
     * @return Pozycja sto�ka w przestrzeni 3D.
     */
    glm::vec3 getPosition();
private:
    float base, height, slices, stacks;
    glm::vec3 position;
    glm::vec3 scale;
    float rotationAngle;
    glm::vec3 rotationAxis;
};

