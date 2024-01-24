#ifndef LIGHT_SOURCE_H
#define LIGHT_SOURCE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

/**
 * @brief Reprezentuje pojedyncze �r�d�o �wiat�a w scenie 3D.
 *
 * Klasa `LightSource` jest odpowiedzialna za reprezentowanie i zarz�dzanie pojedynczym �r�d�em �wiat�a
 * w scenie 3D. Pozwala na konfiguracj� parametr�w �wiat�a takich jak pozycja, kolor, i intensywno��.
 */
class LightSource {
public:
    /**
     * @brief Konstruktor klasy LightSource.
     *
     * Inicjalizuje �r�d�o �wiat�a z podanym identyfikatorem OpenGL.
     *
     * @param lightId Identyfikator �wiat�a w OpenGL.
     */
    LightSource(GLenum lightId);

    /**
     * @brief W��cza �r�d�o �wiat�a.
     *
     * Ustawia flag� 'enabled' na true i w��cza �wiat�o w OpenGL.
     */
    void enable();

    /**
     * @brief Wy��cza �r�d�o �wiat�a.
     *
     * Ustawia flag� 'enabled' na false i wy��cza �wiat�o w OpenGL.
     */
    void disable();

    /**
     * @brief Sprawdza, czy �r�d�o �wiat�a jest w��czone.
     *
     * @return True, je�li �r�d�o �wiat�a jest w��czone, w przeciwnym razie false.
     */
    bool isEnabled() const;

    /**
     * @brief Ustawia pozycj� �r�d�a �wiat�a.
     *
     * @param pos Pozycja �wiat�a w formacie glm::vec4.
     */
    void setPosition(const glm::vec4& position);

    /**
     * @brief Ustawia kolor �wiat�a otoczenia (ambient).
     *
     * @param amb Kolor otoczenia w formacie glm::vec4.
     */
    void setAmbient(const glm::vec4& ambient);

    /**
     * @brief Ustawia kolor �wiat�a rozproszonego (diffuse).
     *
     * @param diff Kolor rozproszenia w formacie glm::vec4.
     */
    void setDiffuse(const glm::vec4& diffuse);

    /**
     * @brief Ustawia kolor �wiat�a lustrzanego (specular).
     *
     * @param spec Kolor lustrzany w formacie glm::vec4.
     */
    void setSpecular(const glm::vec4& specular);

    // Gettery dla parametr�w �wiat�a.
    GLenum getLightId() const;
    glm::vec4 getPosition() const;
    glm::vec4 getAmbient() const;
    glm::vec4 getDiffuse() const;
    glm::vec4 getSpecular() const;

private:
    GLenum lightId;       ///< Identyfikator �wiat�a w OpenGL.
    bool enabled;         ///< Stan w��czenia �wiat�a.
    glm::vec4 position;   ///< Pozycja �wiat�a.
    glm::vec4 ambient;    ///< Kolor �wiat�a otoczenia.
    glm::vec4 diffuse;    ///< Kolor �wiat�a rozproszonego.
    glm::vec4 specular;   ///< Kolor �wiat�a lustrzanego.
};

#endif // LIGHT_SOURCE_H
