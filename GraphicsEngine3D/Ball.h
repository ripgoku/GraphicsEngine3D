#pragma once

#include <GL/glew.h>
#include "Object.h"
#include "Texture.h"

/**
 * @brief Klasa reprezentuj¹ca obiekt 3D typu 'kula' w silniku graficznym.
 *
 * Klasa `Ball` odpowiada za tworzenie, zarz¹dzanie i renderowanie obiektu 3D w kszta³cie kuli.
 * Umo¿liwia konfiguracjê takich aspektów jak rozmiar, pozycja, rotacja, skalowanie, a tak¿e
 * umo¿liwia na³o¿enie tekstury na powierzchniê kuli.
 */
class Ball : public Object
{
public:
    /**
     * @brief Konstruktor klasy Ball.
     *
     * Inicjalizuje obiekt Ball z podanymi parametrami: promieñ, liczba wycinków i stosów, oraz typ materia³u.
     * Ustawia domyœlne wartoœci dla pozycji, skali i rotacji kuli.
     *
     * @param radius Promieñ kuli.
     * @param slices Liczba wycinków (segmentów poziomych) kuli.
     * @param stacks Liczba stosów (segmentów pionowych) kuli.
     * @param type Typ materia³u, z którego jest wykonana kula.
     */
    Ball(float radius, int slices, int stacks, Material type);

    /**
     * @brief Rysuje kulê.
     *
     * Wykonuje transformacje i rysuje kule przy u¿yciu funkcji glutSolidSphere. Stosuje materia³
     * i transformacje okreœlone w obiekcie.
     */
    void draw() const override;

    /**
     * @brief Ustawia pozycjê kuli.
     *
     * @param newPosition Nowa pozycja kuli w przestrzeni 3D.
     */
    void setPosition(const glm::vec3& position) override;

    /**
     * @brief Ustawia rotacjê kuli.
     *
     * @param angle K¹t rotacji w stopniach.
     * @param axis Oœ rotacji.
     */
    void setRotation(float angle, const glm::vec3& axis);

    /**
     * @brief Ustawia skalê kuli.
     *
     * @param scl Nowa skala kuli.
     */
    void setScale(const glm::vec3& scale);

    /**
     * @brief Rysuje teksturê na powierzchni kuli.
     *
     * Binduje teksturê i rysuje kulê z teksturowan¹ powierzchni¹.
     * Wykorzystuje GLUquadric do narysowania sfery z teksturowaniem.
     *
     * @param texture Obiekt tekstury do na³o¿enia na kulê.
     */
    void drawTexturedBall(const Texture& texture);

    /**
     * @brief Zwraca aktualn¹ pozycjê kuli.
     *
     * @return Aktualna pozycja kuli w przestrzeni 3D.
     */
    glm::vec3 getPosition();
private:
    float radius, slices, stacks;
    glm::vec3 position;
    glm::vec3 scale;
    float rotationAngle;
    glm::vec3 rotationAxis;
};

