#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

/**
 * @brief Klasa reprezentuj�ca kamer� w silniku graficznym.
 *
 * Klasa `Camera` jest odpowiedzialna za zarz�dzanie i manipulacj� widokiem kamery w przestrzeni 3D.
 * Pozwala na ustawienie pozycji, poruszanie si� oraz obracanie kamery w przestrzeni. Dostarcza tak�e
 * funkcjonalno�ci do przetwarzania ruchu myszy dla p�ynnego sterowania k�tem widzenia.
 */
class Camera {
public:
    /**
     * @brief Konstruktor klasy Camera.
     *
     * Inicjalizuje kamer� z domy�lnymi warto�ciami pozycji, kierunku patrzenia, g�rnej osi, k�ta poziomego,
     * k�ta pionowego, pr�dko�ci ruchu i czu�o�ci na ruch myszy. Wykonuje aktualizacj� wektor�w kamery.
     */
    Camera();

    /**
     * @brief Ustawia now� pozycj� kamery.
     *
     * @param newPosition Nowa pozycja kamery w przestrzeni 3D.
     */
    void setPosition(const glm::vec3& newPosition);

    /**
     * @brief Porusza kamer�.
     *
     * Przesuwa kamer� o podany offset, uwzgl�dniaj�c pr�dko�� ruchu kamery.
     *
     * @param offset Wektor przesuni�cia kamery.
     */
    void move(const glm::vec3& offset);

    /**
     * @brief Obraca kamer�.
     *
     * Obraca kamer� o okre�lon� zmian� k�ta poziomego (yaw) i pionowego (pitch).
     * Ogranicza k�t pionowy, aby zapobiec obracaniu si� do g�ry nogami.
     *
     * @param deltaYaw Zmiana k�ta poziomego (yaw) kamery.
     * @param deltaPitch Zmiana k�ta pionowego (pitch) kamery.
     */
    void rotate(float deltaYaw, float deltaPitch);

    /**
     * @brief Obs�uguje ruch myszy, wp�ywaj�cy na kierunek patrzenia kamery.
     *
     * @param xOffset Zmiana pozycji myszy w poziomie.
     * @param yOffset Zmiana pozycji myszy w pionie.
     * @param constrainPitch Czy ograniczy� k�t pionowy (pitch) kamery.
     */
    void processMouseMovement(float xOffset, float yOffset, bool constrainPitch = true);

    /**
     * @brief Zwraca macierz widoku kamery.
     *
     * @return Macierz widoku kamery.
     */
    glm::mat4 getViewMatrix() const;

    /**
     * @brief Zwraca wektor prawy kamery.
     *
     * @return Wektor prawy kamery.
     */
    glm::vec3 getRightVector() const;

    /**
     * @brief Zwraca wektor przedni kamery.
     *
     * @return Wektor przedni kamery.
     */
    glm::vec3 getFrontVector() const;

private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    float yaw;
    float pitch;
    float movementSpeed;
    float sensitivity;

    /**
     * @brief Aktualizuje wektory kamery na podstawie obecnych k�t�w yaw i pitch.
     */
    void updateCameraVectors();
};
