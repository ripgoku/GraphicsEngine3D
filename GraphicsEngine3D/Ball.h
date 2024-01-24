#pragma once

#include <GL/glew.h>
#include "Object.h"
#include "Texture.h"

/**
 * @brief Klasa reprezentuj�ca obiekt 3D typu 'kula' w silniku graficznym.
 *
 * Klasa `Ball` odpowiada za tworzenie, zarz�dzanie i renderowanie obiektu 3D w kszta�cie kuli.
 * Umo�liwia konfiguracj� takich aspekt�w jak rozmiar, pozycja, rotacja, skalowanie, a tak�e
 * umo�liwia na�o�enie tekstury na powierzchni� kuli.
 */
class Ball : public Object
{
public:
    /**
     * @brief Konstruktor klasy Ball.
     *
     * Inicjalizuje obiekt Ball z podanymi parametrami: promie�, liczba wycink�w i stos�w, oraz typ materia�u.
     * Ustawia domy�lne warto�ci dla pozycji, skali i rotacji kuli.
     *
     * @param radius Promie� kuli.
     * @param slices Liczba wycink�w (segment�w poziomych) kuli.
     * @param stacks Liczba stos�w (segment�w pionowych) kuli.
     * @param type Typ materia�u, z kt�rego jest wykonana kula.
     */
    Ball(float radius, int slices, int stacks, Material type);

    /**
     * @brief Rysuje kul�.
     *
     * Wykonuje transformacje i rysuje kule przy u�yciu funkcji glutSolidSphere. Stosuje materia�
     * i transformacje okre�lone w obiekcie.
     */
    void draw() const override;

    /**
     * @brief Ustawia pozycj� kuli.
     *
     * @param newPosition Nowa pozycja kuli w przestrzeni 3D.
     */
    void setPosition(const glm::vec3& position) override;

    /**
     * @brief Ustawia rotacj� kuli.
     *
     * @param angle K�t rotacji w stopniach.
     * @param axis O� rotacji.
     */
    void setRotation(float angle, const glm::vec3& axis);

    /**
     * @brief Ustawia skal� kuli.
     *
     * @param scl Nowa skala kuli.
     */
    void setScale(const glm::vec3& scale);

    /**
     * @brief Rysuje tekstur� na powierzchni kuli.
     *
     * Binduje tekstur� i rysuje kul� z teksturowan� powierzchni�.
     * Wykorzystuje GLUquadric do narysowania sfery z teksturowaniem.
     *
     * @param texture Obiekt tekstury do na�o�enia na kul�.
     */
    void drawTexturedBall(const Texture& texture);

    /**
     * @brief Zwraca aktualn� pozycj� kuli.
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

