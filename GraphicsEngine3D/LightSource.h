#ifndef LIGHT_SOURCE_H
#define LIGHT_SOURCE_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

/**
 * @brief Reprezentuje pojedyncze Ÿród³o œwiat³a w scenie 3D.
 *
 * Klasa `LightSource` jest odpowiedzialna za reprezentowanie i zarz¹dzanie pojedynczym Ÿród³em œwiat³a
 * w scenie 3D. Pozwala na konfiguracjê parametrów œwiat³a takich jak pozycja, kolor, i intensywnoœæ.
 */
class LightSource {
public:
    /**
     * @brief Konstruktor klasy LightSource.
     *
     * Inicjalizuje Ÿród³o œwiat³a z podanym identyfikatorem OpenGL.
     *
     * @param lightId Identyfikator œwiat³a w OpenGL.
     */
    LightSource(GLenum lightId);

    /**
     * @brief W³¹cza Ÿród³o œwiat³a.
     *
     * Ustawia flagê 'enabled' na true i w³¹cza œwiat³o w OpenGL.
     */
    void enable();

    /**
     * @brief Wy³¹cza Ÿród³o œwiat³a.
     *
     * Ustawia flagê 'enabled' na false i wy³¹cza œwiat³o w OpenGL.
     */
    void disable();

    /**
     * @brief Sprawdza, czy Ÿród³o œwiat³a jest w³¹czone.
     *
     * @return True, jeœli Ÿród³o œwiat³a jest w³¹czone, w przeciwnym razie false.
     */
    bool isEnabled() const;

    /**
     * @brief Ustawia pozycjê Ÿród³a œwiat³a.
     *
     * @param pos Pozycja œwiat³a w formacie glm::vec4.
     */
    void setPosition(const glm::vec4& position);

    /**
     * @brief Ustawia kolor œwiat³a otoczenia (ambient).
     *
     * @param amb Kolor otoczenia w formacie glm::vec4.
     */
    void setAmbient(const glm::vec4& ambient);

    /**
     * @brief Ustawia kolor œwiat³a rozproszonego (diffuse).
     *
     * @param diff Kolor rozproszenia w formacie glm::vec4.
     */
    void setDiffuse(const glm::vec4& diffuse);

    /**
     * @brief Ustawia kolor œwiat³a lustrzanego (specular).
     *
     * @param spec Kolor lustrzany w formacie glm::vec4.
     */
    void setSpecular(const glm::vec4& specular);

    // Gettery dla parametrów œwiat³a.
    GLenum getLightId() const;
    glm::vec4 getPosition() const;
    glm::vec4 getAmbient() const;
    glm::vec4 getDiffuse() const;
    glm::vec4 getSpecular() const;

private:
    GLenum lightId;       ///< Identyfikator œwiat³a w OpenGL.
    bool enabled;         ///< Stan w³¹czenia œwiat³a.
    glm::vec4 position;   ///< Pozycja œwiat³a.
    glm::vec4 ambient;    ///< Kolor œwiat³a otoczenia.
    glm::vec4 diffuse;    ///< Kolor œwiat³a rozproszonego.
    glm::vec4 specular;   ///< Kolor œwiat³a lustrzanego.
};

#endif // LIGHT_SOURCE_H
