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
 * @brief Klasa g³ówna silnika graficznego.
 *
 * Klasa `Engine` zarz¹dza g³ównymi funkcjami silnika graficznego, takimi jak inicjalizacja,
 * renderowanie, obs³uga zdarzeñ klawiatury i myszy, oraz pêtla g³ówna aplikacji.
 */
class Engine {
public:
    /**
     * @brief Konstruktor klasy Engine.
     *
     * Inicjalizuje podstawowe parametry silnika graficznego, w tym ustawienia okna i domyœlne parametry kamery.
     * Przygotowuje równie¿ domyœln¹ konfiguracjê œrodowiska, tak¹ jak fullscreen czy czêstotliwoœæ odœwie¿ania.
     *
     * @param argc Liczba argumentów przekazanych do programu.
     * @param argv Tablica argumentów przekazanych do programu.
     */
    Engine(int argc, char** argv);

    /**
     * @brief Destruktor klasy Engine.
     *
     * Odpowiada za czyszczenie zasobów i zakoñczenie dzia³ania programu.
     */
    ~Engine();

    /**
     * @brief Inicjalizuje silnik graficzny.
     *
     * Ustawia parametry okna, inicjalizuje GLEW, konfiguruje funkcje callback i uruchamia g³ówn¹ pêtlê renderowania.
     *
     * @param width Szerokoœæ okna.
     * @param height Wysokoœæ okna.
     * @param fullscreen Tryb pe³noekranowy.
     * @param name Nazwa okna.
     */
    void init(int width, int height, bool fullscreen, const char* name);

    /**
     * @brief Rozpoczyna g³ówn¹ pêtlê aplikacji.
     */
    void run();

    /**
     * @brief Zamyka silnik.
     *
     * Funkcja `shutdown` ustawia flagê `isRunning` na false, co prowadzi do zakoñczenia g³ównej pêtli gry
     * i zamkniêcia aplikacji. Jest to wa¿ne dla prawid³owego zwolnienia zasobów i zakoñczenia dzia³ania programu.
     */
    void shutdown();

    /**
     * @brief Renderuje scenê.
     *
     * Odpowiada za rysowanie obiektów w scenie z u¿yciem kamery, œwiat³a i tekstur.
     */
    static void render();

    /**
     * @brief Obs³uguje zmianê rozmiaru okna.
     *
     * Dostosowuje widok do nowego rozmiaru okna.
     *
     * @param width Nowa szerokoœæ okna.
     * @param height Nowa wysokoœæ okna.
     */
    static void reshape(int width, int height);

    /**
     * @brief Obs³uguje wejœcie z klawiatury.
     *
     * Odpowiada za obs³ugê zdarzeñ klawiatury, takich jak ruch kamery i inne akcje.
     *
     * @param key Kod klawisza.
     * @param x Pozycja kursora X.
     * @param y Pozycja kursora Y.
     */
    static void keyboard(unsigned char key, int x, int y);

    /**
     * @brief Obs³uguje zdarzenia zwolnienia klawisza klawiatury.
     *
     * @param key Kod klawisza.
     * @param x Pozycja kursora X.
     * @param y Pozycja kursora Y.
     */
    static void keyboardUp(unsigned char key, int x, int y);

    /**
     * @brief Timer silnika.
     *
     * Odpowiada za aktualizacjê stanu gry i ponowne renderowanie sceny w okreœlonych odstêpach czasu.
     *
     * @param value Wartoœæ przekazywana do timera.
     */
    static void timer(int value);

    /**
     * @brief Obs³uguje ruch myszy.
     *
     * Odpowiada za obs³ugê ruchu myszy i rotacjê kamery.
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
     * Ustawia test g³êbokoœci, kolor t³a i inne podstawowe konfiguracje.
     */
    void initGL();

    /**
     * @brief Ustawia widok kamery.
     *
     * Konfiguruje viewport i macierze projekcji oraz modelu widoku.
     */
    static void setupViewport();

    /**
     * @brief Obs³uguje wejœcie od u¿ytkownika.
     *
     * Funkcja `handleInput` odpowiada za reakcjê silnika na akcje u¿ytkownika, takie jak naciœniêcia klawiszy.
     * Ka¿de wciœniêcie klawisza powoduje odpowiedni¹ reakcjê kamery, tak¹ jak przemieszczenie lub obrót.
     * Funkcja jest wywo³ywana w pêtli g³ównej gry, aby zapewniæ ci¹g³¹ odpowiedŸ na wejœcie u¿ytkownika.
     */
    void handleInput();

    /**
     * @brief Aktualizuje stan silnika.
     *
     * Odpowiada za aktualizacjê stanu gry, w tym pozycji obiektów, œwiate³ i kamery.
     */
    static void update();

    /**
     * @brief Czyœci zasoby silnika.
     *
     * Odpowiada za czyszczenie zasobów i zamykanie okna.
     */
    void cleanUp();
};