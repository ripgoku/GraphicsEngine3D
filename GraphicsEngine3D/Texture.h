#pragma once

#include <GL/glew.h>
#include <string>
#include <iostream>

/**
 * @brief Klasa reprezentuj�ca tekstur� w OpenGL.
 *
 * Klasa `Texture` zarz�dza teksturami 2D u�ywanymi w scenie OpenGL. Pozwala na �adowanie,
 * wi�zanie i zarz�dzanie teksturami z plik�w graficznych.
 */
class Texture {
public:
    /**
     * @brief Konstruktor domy�lny tworz�cy pust� tekstur�.
     */
    Texture();

    /**
     * @brief Destruktor zwalniaj�cy zasoby tekstury.
     */
    ~Texture();

    /**
     * @brief Wi��e tekstur� do wybranego slotu tekstur.
     *
     * @param slot Numer slotu tekstury, domy�lnie 0.
     */
    void bind(unsigned int slot = 0) const;

    /**
     * @brief �aduje tekstur� z podanej �cie�ki pliku.
     *
     * @param path �cie�ka do pliku tekstury.
     */
    void loadTexture(const std::string& path);

private:
    unsigned int ID;    ///< ID tekstury w OpenGL.
};