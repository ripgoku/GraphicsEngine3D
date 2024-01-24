#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Camera.h"
#include "LightingManager.h"
#include "LightSource.h"
#include "Cube.h"
#include "Ball.h"
#include "Cone.h"
#include "Texture.h"

/**
 * @brief Klasa g��wna silnika graficznego.
 *
 * Klasa `Engine` zarz�dza g��wnymi funkcjami silnika graficznego, takimi jak inicjalizacja,
 * renderowanie, obs�uga zdarze� klawiatury i myszy, oraz p�tla g��wna aplikacji.
 */
class Engine {
public:
    /**
     * @brief Konstruktor klasy Engine.
     *
     * Inicjalizuje podstawowe parametry silnika graficznego, w tym ustawienia okna i domy�lne parametry kamery.
     * Przygotowuje r�wnie� domy�ln� konfiguracj� �rodowiska, tak� jak fullscreen czy cz�stotliwo�� od�wie�ania.
     *
     * @param argc Liczba argument�w przekazanych do programu.
     * @param argv Tablica argument�w przekazanych do programu.
     */
    Engine(int argc, char** argv);

    /**
     * @brief Destruktor klasy Engine.
     *
     * Odpowiada za czyszczenie zasob�w i zako�czenie dzia�ania programu.
     */
    ~Engine();

    /**
     * @brief Inicjalizuje silnik graficzny.
     *
     * Ustawia parametry okna, inicjalizuje GLEW, konfiguruje funkcje callback i uruchamia g��wn� p�tl� renderowania.
     *
     * @param width Szeroko�� okna.
     * @param height Wysoko�� okna.
     * @param fullscreen Tryb pe�noekranowy.
     * @param name Nazwa okna.
     */
    void init(int width, int height, bool fullscreen, const char* name);

    /**
     * @brief Rozpoczyna g��wn� p�tl� aplikacji.
     */
    void run();

    /**
     * @brief Zamyka silnik.
     *
     * Funkcja `shutdown` ustawia flag� `isRunning` na false, co prowadzi do zako�czenia g��wnej p�tli gry
     * i zamkni�cia aplikacji. Jest to wa�ne dla prawid�owego zwolnienia zasob�w i zako�czenia dzia�ania programu.
     */
    void shutdown();

    /**
     * @brief Renderuje scen�.
     *
     * Odpowiada za rysowanie obiekt�w w scenie z u�yciem kamery, �wiat�a i tekstur.
     */
    static void render();

    /**
     * @brief Obs�uguje zmian� rozmiaru okna.
     *
     * Dostosowuje widok do nowego rozmiaru okna.
     *
     * @param width Nowa szeroko�� okna.
     * @param height Nowa wysoko�� okna.
     */
    static void reshape(int width, int height);

    /**
     * @brief Obs�uguje wej�cie z klawiatury.
     *
     * Odpowiada za obs�ug� zdarze� klawiatury, takich jak ruch kamery i inne akcje.
     *
     * @param key Kod klawisza.
     * @param x Pozycja kursora X.
     * @param y Pozycja kursora Y.
     */
    static void keyboard(unsigned char key, int x, int y);

    /**
     * @brief Obs�uguje zdarzenia zwolnienia klawisza klawiatury.
     *
     * @param key Kod klawisza.
     * @param x Pozycja kursora X.
     * @param y Pozycja kursora Y.
     */
    static void keyboardUp(unsigned char key, int x, int y);

    /**
     * @brief Timer silnika.
     *
     * Odpowiada za aktualizacj� stanu gry i ponowne renderowanie sceny w okre�lonych odst�pach czasu.
     *
     * @param value Warto�� przekazywana do timera.
     */
    static void timer(int value);

    /**
     * @brief Obs�uguje ruch myszy.
     *
     * Odpowiada za obs�ug� ruchu myszy i rotacj� kamery.
     *
     * @param x Pozycja kursora X.
     * @param y Pozycja kursora Y.
     */
    static void mouseMotion(int x, int y);

private:
    static Camera camera;
    static int windowWidth;
    static int windowHeight;
    static int framesPerSecond;
    static bool isFullscreen;
    bool isRunning;
    const char* windowTitle;
    static bool isCursorCaptured;
    static bool isWKeyPressed;
    static bool isSKeyPressed;
    static bool isAKeyPressed;
    static bool isDKeyPressed;
    static Ball sun;

    /**
     * @brief Konfiguruje podstawowe ustawienia OpenGL.
     *
     * Ustawia test g��boko�ci, kolor t�a i inne podstawowe konfiguracje.
     */
    void initGL();

    /**
     * @brief Ustawia widok kamery.
     *
     * Konfiguruje viewport i macierze projekcji oraz modelu widoku.
     */
    static void setupViewport();

    /**
     * @brief Obs�uguje wej�cie od u�ytkownika.
     *
     * Funkcja `handleInput` odpowiada za reakcj� silnika na akcje u�ytkownika, takie jak naci�ni�cia klawiszy.
     * Ka�de wci�ni�cie klawisza powoduje odpowiedni� reakcj� kamery, tak� jak przemieszczenie lub obr�t.
     * Funkcja jest wywo�ywana w p�tli g��wnej gry, aby zapewni� ci�g�� odpowied� na wej�cie u�ytkownika.
     */
    void handleInput();

    /**
     * @brief Aktualizuje stan silnika.
     *
     * Odpowiada za aktualizacj� stanu gry, w tym pozycji obiekt�w, �wiate� i kamery.
     */
    static void update();

    /**
     * @brief Czy�ci zasoby silnika.
     *
     * Odpowiada za czyszczenie zasob�w i zamykanie okna.
     */
    void cleanUp();
};