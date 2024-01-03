#include "Engine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

int Engine::windowWidth;
int Engine::windowHeight;
int Engine::framesPerSecond;
Camera Engine::camera;
bool Engine::isCursorCaptured;
bool Engine::isWKeyPressed;
bool Engine::isSKeyPressed;
bool Engine::isAKeyPressed;
bool Engine::isDKeyPressed;

Engine::Engine(int argc, char** argv) {
    glutInit(&argc, argv);
    isFullscreen = false;
    isRunning = false;
    windowWidth = 1280;
    windowHeight = 720;
    windowTitle = "OpenGL Engine";
    framesPerSecond = 60;
    isCursorCaptured = true;
    isWKeyPressed = false;
    isSKeyPressed = false;
    isAKeyPressed = false;
    isDKeyPressed = false;
}

Engine::~Engine() {
}

void Engine::mouseMotion(int x, int y) {
    static int lastX = windowWidth / 2;
    static int lastY = windowHeight / 2;

    // SprawdŸ czy kursor jest przechwytywany
    if (isCursorCaptured) {
        // Oblicz ró¿nicê pozycji myszy
        float xOffset = x - lastX;
        float yOffset = lastY - y;

        // Obróæ kamerê na podstawie ruchu myszy
        camera.rotate(xOffset, yOffset);

        // Ustaw kursor myszy w œrodku okna
        glutWarpPointer(windowWidth / 2, windowHeight / 2);

        lastX = windowWidth / 2;
        lastY = windowHeight / 2;
    }
}


void Engine::init(int width, int height, bool fullscreen, const char* name) {
    windowWidth = width;
    windowHeight = height;
    isFullscreen = fullscreen;
    windowTitle = name;

    // Inicjacja GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow(windowTitle);
    if (isFullscreen) {
        glutFullScreen();
    }

    // Inicjacja GLEW
    GLenum glewStatus = glewInit();
    if (glewStatus != GLEW_OK) {
        fprintf(stderr, "glewInit error: %s\n", glewGetErrorString(glewStatus));
        exit(EXIT_FAILURE);
    }

    // Ustawienie funkcji do obs³ugi zdarzeñ
    glutDisplayFunc(Engine::render); // Funkcja renderuj¹ca
    glutReshapeFunc(Engine::reshape); // Funkcja do obs³ugi zmiany rozmiaru okna
    glutKeyboardFunc(Engine::keyboard); // Funkcja do obs³ugi klawiatury
    glutKeyboardUpFunc(Engine::keyboardUp); // Funkcja do obs³ugi zwolnienia klawiszy
    glutPassiveMotionFunc(Engine::mouseMotion); // Funkcja do obs³ugi ruchu myszy
    glutTimerFunc(1000 / framesPerSecond, Engine::timer, 0);

    initGL();
}

void Engine::run() {
    isRunning = true;

    glutSetCursor(GLUT_CURSOR_NONE);

    glutMainLoop();
}

void Engine::shutdown() {
    isRunning = false;
}

void Engine::initGL() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Inne inicjalizacje OpenGL, takie jak ustawienia cieni, tekstur, itp.
}

void Engine::setupViewport() {
    glViewport(0, 0, windowWidth, windowHeight);

    glm::mat4 projection = glm::perspective(glm::radians(60.0f), static_cast<float>(windowWidth) / static_cast<float>(windowHeight), 0.1f, 100.0f);
    glm::mat4 view = camera.getViewMatrix(); // U¿yj macierzy widoku z kamery

    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(glm::value_ptr(projection));
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(glm::value_ptr(view));
}


void Engine::handleInput() {
    if (isWKeyPressed) {
        // Poruszanie do przodu
        camera.move(glm::vec3(-1.0f, 0.0f, 0.0f));
    }
    if (isSKeyPressed) {
        // Poruszanie do ty³u
        camera.move(glm::vec3(1.0f, 0.0f, 0.0f));
    }
    if (isAKeyPressed) {
        // Przesuniêcie w lewo
        camera.move(glm::vec3(0.0f, 0.0f, -1.0f));
    }
    if (isDKeyPressed) {
        // Przesuniêcie w prawo
        camera.move(glm::vec3(0.0f, 0.0f, 1.0f));
    }
}

void Engine::update() {
    // Aktualizacja logiki gry
}

void Engine::render() {
    // Tutaj umieœæ kod renderuj¹cy scenê
    // Na przyk³ad, wyczyszczenie bufora koloru i g³êbokoœci
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Ustaw viewport i perspektywê
    setupViewport();

    // Przyk³adowe rysowanie obiektów za pomoc¹ klasy GeometryDrawer
    glColor3f(1.0f, 1.0f, 1.0f);
    //GeometryDrawer::drawCube(1.0f);
    //GeometryDrawer::drawFilledCube(0.5f);
    //GeometryDrawer::drawSphere(0.5f, 20, 20);
    //GeometryDrawer::drawCone(0.5f, 1.0f, 20, 20);

    // Dodatkowe rysowanie osi
    GeometryDrawer::drawAxes(1.0f);

    //PrimitiveDrawer::drawPoint(0.0f, 0.0f, 0.0f, 3.0f, 1.0f, 0.0f, 0.0f); // Czerwony punkt
    //PrimitiveDrawer::drawLine(-3.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f); // Zielona linia
    //PrimitiveDrawer::drawTriangle(-1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f); // Niebieski trójk¹t

    // Przyk³adowe rysowanie szeœcianu
    TransformableCube myCube(1.0f);
    myCube.translate(glm::vec3(1.0f, 0.0f, 0.0f));
    myCube.rotate(45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
    myCube.scale(glm::vec3(2.0f, 1.0f, 1.0f));
    myCube.draw(1.0f, 1.0f, 1.0f);

    // SprawdŸ czy kursor jest przechwytywany
    if (isCursorCaptured) {
        // Ustaw kursor myszy w œrodku okna
        glutWarpPointer(windowWidth / 2, windowHeight / 2);
    }

    // Na koniec, podmiana buforów
    glutSwapBuffers();
}

void Engine::reshape(int width, int height) {
    windowWidth = width;
    windowHeight = height;
    setupViewport();
}

void Engine::keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 27: // ESC
        exit(EXIT_SUCCESS);
        break;
    case 'a':
        camera.move(camera.getRightVector() * -1.0f);
        break;
    case 'd':
        camera.move(camera.getRightVector());
        break;
    case 's':
        camera.move(camera.getFrontVector() * -1.0f);
        break;
    case 'w':
        camera.move(camera.getFrontVector());
        break;
    case '\t':
        isCursorCaptured = !isCursorCaptured;
        if (isCursorCaptured) {
            glutSetCursor(GLUT_CURSOR_NONE);
            glutWarpPointer(windowWidth / 2, windowHeight / 2);
        }
        else {
            glutSetCursor(GLUT_CURSOR_INHERIT);
        }
        break;
        // ...
    }
}

void Engine::keyboardUp(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        isWKeyPressed = false;
        break;
    case 'S':
    case 's':
        isSKeyPressed = false;
        break;
    case 'A':
    case 'a':
        isAKeyPressed = false;
        break;
    case 'D':
    case 'd':
        isDKeyPressed = false;
        break;
    }
}

void Engine::cleanUp() {
    // Sprz¹tanie pamiêci, zamkniêcie okna itp.
    glutDestroyWindow(glutGetWindow());
}

void Engine::timer(int value) {
    glutPostRedisplay(); // Przerysuj scenê
    glutTimerFunc(1000 / framesPerSecond, Engine::timer, 0); // Ponownie ustaw timer
}
