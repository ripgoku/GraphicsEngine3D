#ifndef LIGHTING_MANAGER_H
#define LIGHTING_MANAGER_H

#include <GL/glew.h>
#include "LightSource.h"
#include <vector>

/**
 * @brief Zarz¹dza oœwietleniem w scenie 3D.
 *
 * Klasa `LightingManager` jest odpowiedzialna za zarz¹dzanie Ÿród³ami œwiat³a w scenie 3D.
 * Umo¿liwia dodawanie Ÿróde³ œwiat³a oraz ich aplikacjê do sceny.
 */
class LightingManager {
public:
    /**
     * @brief Konstruktor klasy LightingManager.
     *
     * Inicjalizuje mened¿er oœwietlenia, w³¹czaj¹c obs³ugê oœwietlenia w OpenGL.
     */
    LightingManager();

    /**
     * @brief Dodaje Ÿród³o œwiat³a do mened¿era.
     *
     * Dodaje Ÿród³o œwiat³a do listy zarz¹dzanych Ÿróde³, co pozwala na jego póŸniejsze zastosowanie w scenie.
     *
     * @param light Referencja do obiektu klasy LightSource reprezentuj¹cego dodawane Ÿród³o œwiat³a.
     */
    void addLightSource(const LightSource& light);

    /**
     * @brief Aplikuje skonfigurowane Ÿród³a œwiat³a do sceny.
     *
     * Iteruje przez listê zarz¹dzanych Ÿróde³ œwiat³a, aplikuj¹c ich ustawienia do aktualnej sceny w OpenGL.
     * Pomija Ÿród³a œwiat³a, które nie s¹ w³¹czone.
     */
    void applyLighting();

private:
    std::vector<LightSource> lightSources; ///< Lista zarz¹dzanych Ÿróde³ œwiat³a.
};

#endif // LIGHTING_MANAGER_H
