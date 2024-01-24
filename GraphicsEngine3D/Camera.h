#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

/**
 * @brief Klasa reprezentuj¹ca kamerê w silniku graficznym.
 *
 * Klasa `Camera` jest odpowiedzialna za zarz¹dzanie i manipulacjê widokiem kamery w przestrzeni 3D.
 * Pozwala na ustawienie pozycji, poruszanie siê oraz obracanie kamery w przestrzeni. Dostarcza tak¿e
 * funkcjonalnoœci do przetwarzania ruchu myszy dla p³ynnego sterowania k¹tem widzenia.
 */
class Camera {
public:
    /**
     * @brief Konstruktor klasy Camera.
     *
     * Inicjalizuje kamerê z domyœlnymi wartoœciami pozycji, kierunku patrzenia, górnej osi, k¹ta poziomego,
     * k¹ta pionowego, prêdkoœci ruchu i czu³oœci na ruch myszy. Wykonuje aktualizacjê wektorów kamery.
     */
    Camera();

    /**
     * @brief Ustawia now¹ pozycjê kamery.
     *
     * @param newPosition Nowa pozycja kamery w przestrzeni 3D.
     */
    void setPosition(const glm::vec3& newPosition);

    /**
     * @brief Porusza kamer¹.
     *
     * Przesuwa kamerê o podany offset, uwzglêdniaj¹c prêdkoœæ ruchu kamery.
     *
     * @param offset Wektor przesuniêcia kamery.
     */
    void move(const glm::vec3& offset);

    /**
     * @brief Obraca kamerê.
     *
     * Obraca kamerê o okreœlon¹ zmianê k¹ta poziomego (yaw) i pionowego (pitch).
     * Ogranicza k¹t pionowy, aby zapobiec obracaniu siê do góry nogami.
     *
     * @param deltaYaw Zmiana k¹ta poziomego (yaw) kamery.
     * @param deltaPitch Zmiana k¹ta pionowego (pitch) kamery.
     */
    void rotate(float deltaYaw, float deltaPitch);

    /**
     * @brief Obs³uguje ruch myszy, wp³ywaj¹cy na kierunek patrzenia kamery.
     *
     * @param xOffset Zmiana pozycji myszy w poziomie.
     * @param yOffset Zmiana pozycji myszy w pionie.
     * @param constrainPitch Czy ograniczyæ k¹t pionowy (pitch) kamery.
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
     * @brief Aktualizuje wektory kamery na podstawie obecnych k¹tów yaw i pitch.
     */
    void updateCameraVectors();
};
