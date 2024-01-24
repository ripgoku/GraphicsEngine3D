#pragma once

#include <GL/glew.h>
#include "Object.h"

/**
 * @brief Klasa reprezentuj¹ca sto¿ek 3D w silniku graficznym.
 *
 * Klasa `Cone` dziedziczy po klasie `Object` i jest odpowiedzialna za reprezentacjê
 * sto¿ka 3D. Pozwala na ustawienie podstawowych parametrów geometrycznych sto¿ka,
 * takich jak wymiary podstawy i wysokoœci, liczby wycinków i stosów oraz materia³u.
 * Umo¿liwia tak¿e manipulacjê po³o¿eniem, rotacj¹ i skalowaniem sto¿ka.
 */
class Cone : public Object
{
public:
    /**
     * @brief Konstruktor klasy Cone.
     *
     * Inicjalizuje sto¿ek z podanymi parametrami: baz¹, wysokoœci¹, liczb¹ wycinków i stosów,
     * oraz materia³em. Ustawia równie¿ domyœlne wartoœci transformacji (pozycji, skalowania, obrotu).
     *
     * @param base Promieñ podstawy sto¿ka.
     * @param height Wysokoœæ sto¿ka.
     * @param slices Liczba wycinków wokó³ osi Y.
     * @param stacks Liczba stosów wzd³u¿ osi Y.
     * @param type Typ materia³u.
     */
    Cone(float base, float height, int slices, int stacks, Material type);

    /**
     * @brief Rysuje sto¿ek w scenie.
     *
     * Przygotowuje transformacje sto¿ka, a nastêpnie rysuje go z zastosowaniem materia³u.
     */
    void draw() const override;

    /**
     * @brief Ustawia now¹ pozycjê sto¿ka.
     *
     * @param newPosition Nowa pozycja sto¿ka w przestrzeni 3D.
     */
    void setPosition(const glm::vec3& position) override;

    /**
     * @brief Ustawia obrót sto¿ka.
     *
     * @param angle K¹t obrotu w stopniach.
     * @param axis Oœ obrotu.
     */
    void setRotation(float angle, const glm::vec3& axis);

    /**
     * @brief Ustawia skalowanie sto¿ka.
     *
     * @param scl Wektor skalowania.
     */
    void setScale(const glm::vec3& scale);

    /**
     * @brief Zwraca obecn¹ pozycjê sto¿ka.
     *
     * @return Pozycja sto¿ka w przestrzeni 3D.
     */
    glm::vec3 getPosition();
private:
    float base, height, slices, stacks;
    glm::vec3 position;
    glm::vec3 scale;
    float rotationAngle;
    glm::vec3 rotationAxis;
};

