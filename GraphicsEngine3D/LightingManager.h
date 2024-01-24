#ifndef LIGHTING_MANAGER_H
#define LIGHTING_MANAGER_H

#include <GL/glew.h>
#include "LightSource.h"
#include <vector>

/**
 * @brief Zarz�dza o�wietleniem w scenie 3D.
 *
 * Klasa `LightingManager` jest odpowiedzialna za zarz�dzanie �r�d�ami �wiat�a w scenie 3D.
 * Umo�liwia dodawanie �r�de� �wiat�a oraz ich aplikacj� do sceny.
 */
class LightingManager {
public:
    /**
     * @brief Konstruktor klasy LightingManager.
     *
     * Inicjalizuje mened�er o�wietlenia, w��czaj�c obs�ug� o�wietlenia w OpenGL.
     */
    LightingManager();

    /**
     * @brief Dodaje �r�d�o �wiat�a do mened�era.
     *
     * Dodaje �r�d�o �wiat�a do listy zarz�dzanych �r�de�, co pozwala na jego p�niejsze zastosowanie w scenie.
     *
     * @param light Referencja do obiektu klasy LightSource reprezentuj�cego dodawane �r�d�o �wiat�a.
     */
    void addLightSource(const LightSource& light);

    /**
     * @brief Aplikuje skonfigurowane �r�d�a �wiat�a do sceny.
     *
     * Iteruje przez list� zarz�dzanych �r�de� �wiat�a, aplikuj�c ich ustawienia do aktualnej sceny w OpenGL.
     * Pomija �r�d�a �wiat�a, kt�re nie s� w��czone.
     */
    void applyLighting();

private:
    std::vector<LightSource> lightSources; ///< Lista zarz�dzanych �r�de� �wiat�a.
};

#endif // LIGHTING_MANAGER_H
