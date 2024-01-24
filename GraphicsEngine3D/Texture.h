#pragma once

#include <GL/glew.h>
#include <string>
#include <iostream>

/**
 * @brief Klasa reprezentuj¹ca teksturê w OpenGL.
 *
 * Klasa `Texture` zarz¹dza teksturami 2D u¿ywanymi w scenie OpenGL. Pozwala na ³adowanie,
 * wi¹zanie i zarz¹dzanie teksturami z plików graficznych.
 */
class Texture {
public:
    /**
     * @brief Konstruktor domyœlny tworz¹cy pust¹ teksturê.
     */
    Texture();

    /**
     * @brief Destruktor zwalniaj¹cy zasoby tekstury.
     */
    ~Texture();

    /**
     * @brief Wi¹¿e teksturê do wybranego slotu tekstur.
     *
     * @param slot Numer slotu tekstury, domyœlnie 0.
     */
    void bind(unsigned int slot = 0) const;

    /**
     * @brief £aduje teksturê z podanej œcie¿ki pliku.
     *
     * @param path Œcie¿ka do pliku tekstury.
     */
    void loadTexture(const std::string& path);

private:
    unsigned int ID;    ///< ID tekstury w OpenGL.
};