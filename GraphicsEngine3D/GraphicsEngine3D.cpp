#pragma comment(lib, "freeglut.lib")

#include <GL/glew.h>
#include <iostream>
#include "Engine.h"

/**
 * @brief Punkt wejściowy programu.
 *
 * Funkcja `main` jest głównym punktem wejściowym dla aplikacji graficznej. Inicjalizuje silnik gry (`Engine`),
 * konfiguruje podstawowe parametry okna, takie jak rozmiar i tytuł, a następnie przechodzi do głównej pętli
 * obsługi zdarzeń GLUT. Program zakończy się, gdy główna pętla zostanie zamknięta.
 *
 * @param argc Liczba argumentów wiersza poleceń.
 * @param argv Tablica argumentów wiersza poleceń.
 * @return Kod zakończenia programu. Zwraca 0, gdy program zakończy działanie prawidłowo.
 */
int main(int argc, char** argv)
{
    Engine engine(argc, argv);
    engine.init(1280, 720, false, "Example title");
    glutMainLoop();
    return 0;
}