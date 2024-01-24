#pragma once

#include <GL/glew.h>
#include "Object.h"
#include "Texture.h"

/**
 * @brief Klasa reprezentuj¹ca kostkê 3D w silniku graficznym.
 *
 * Klasa `Cube` dziedziczy po klasie `Object` i jest odpowiedzialna za reprezentacjê
 * kostki 3D. Umo¿liwia ustawienie rozmiaru, po³o¿enia, rotacji, skalowania oraz tekstury kostki.
 * Zawiera metody do rysowania kostki zarówno z tekstur¹ jak i bez.
 */
class Cube : public Object
{
public:
    /**
     * @brief Konstruktor klasy Cube.
     *
     * Inicjalizuje szeœcian o podanym rozmiarze i materiale. Ustawia równie¿ domyœlne wartoœci
     * transformacji (pozycji, skalowania, obrotu).
     *
     * @param size Rozmiar krawêdzi szeœcianu.
     * @param type Typ materia³u.
     */
    Cube(float size, Material type);

    /**
     * @brief Rysuje szeœcian w scenie.
     *
     * Przygotowuje transformacje szeœcianu, a nastêpnie rysuje go z zastosowaniem materia³u.
     */
    void draw() const override;

    /**
     * @brief Ustawia now¹ pozycjê szeœcianu.
     *
     * @param newPosition Nowa pozycja szeœcianu w przestrzeni 3D.
     */
    void setPosition(const glm::vec3& position);

    /**
     * @brief Ustawia obrót szeœcianu.
     *
     * @param angle K¹t obrotu w stopniach.
     * @param axis Oœ obrotu.
     */
    void setRotation(float angle, const glm::vec3& axis);

    /**
     * @brief Ustawia skalowanie szeœcianu.
     *
     * @param scl Wektor skalowania.
     */
    void setScale(const glm::vec3& scale);

    /**
     * @brief Rysuje szeœcian z tekstur¹.
     *
     * Powi¹zuje teksturê z szeœcianem, a nastêpnie rysuje go w scenie.
     *
     * @param texture Tekstura do na³o¿enia na szeœcian.
     */
    void drawTexturedCube(const Texture& texture);

    /**
     * @brief Zwraca obecn¹ pozycjê szeœcianu.
     *
     * @return Pozycja szeœcianu w przestrzeni 3D.
     */
    glm::vec3 getPosition();
private:
    float size;
    glm::vec3 position;
    glm::vec3 scale;
    float rotationAngle;
    glm::vec3 rotationAxis;
};

