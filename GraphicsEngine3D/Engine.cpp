#include "Engine.h"

int Engine::windowWidth;
int Engine::windowHeight;
int Engine::framesPerSecond;
Camera Engine::camera;
bool Engine::isCursorCaptured;
bool Engine::isWKeyPressed;
bool Engine::isSKeyPressed;
bool Engine::isAKeyPressed;
bool Engine::isDKeyPressed;
bool Engine::isFullscreen;
LightSource light(GL_LIGHT0);
Ball Engine::sun = Ball(0.2, 100, 100, Material::Glass);

Engine::Engine(int argc, char** argv) {
    glutInit(&argc, argv);
    isFullscreen = true;
    isRunning = false;
    windowWidth = 1280;
    windowHeight = 720;
    windowTitle = "OpenGL Engine";
    framesPerSecond = 60;
    isCursorCaptured = false;
    isWKeyPressed = false;
    isSKeyPressed = false;
    isAKeyPressed = false;
    isDKeyPressed = false;
}

Engine::~Engine() {
}

void Engine::init(int width, int height, bool fullscreen, const char* name) {
    windowWidth = width;
    windowHeight = height;
    isFullscreen = fullscreen;
    windowTitle = name;

    sun.setPosition(glm::vec3(3, 2, 0));

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

void Engine::initGL() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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

void Engine::run() {
    isRunning = true;

    glutSetCursor(GLUT_CURSOR_NONE);

    glutMainLoop();
}

void Engine::shutdown() {
    isRunning = false;
}

void Engine::update() {
    static float angle = 0.0f;
    float deltaTime = 1.0f / 10;
    angle += 0.1f * deltaTime;

    // Obliczanie nowej pozycji na orbicie
    float x = 3.0f + 4.0f * cos(angle);
    float z = -1.0f + 4.0f * sin(angle);

    sun.setPosition(glm::vec3(x, 2, z));


}

void Engine::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    setupViewport();

    LightingManager lightingManager;

    glm::vec3 lightPosition = sun.getPosition();

    light.setPosition(glm::vec4(lightPosition, 1.0f));
    light.setAmbient(glm::vec4(0.2f, 0.2f, 0.2f, 1.0f));
    light.setDiffuse(glm::vec4(0.8f, 0.8f, 0.8f, 1.0f));
    light.setSpecular(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    lightingManager.addLightSource(light);
    lightingManager.applyLighting();
    Texture sunTexture;
    sunTexture.loadTexture("Textury/sun.jpg");
    sun.drawTexturedBall(sunTexture);

    Ball background(20, 100, 100, Material::Sand);
    background.setPosition(glm::vec3(0, 0, 0));
    background.setColor(0.6, 0.6, 1, 1);
    background.draw();

    Texture grassTexture;
    grassTexture.loadTexture("Textury/grass.jpg");
    Cube ssand(1, Material::Sand);
    ssand.setPosition(glm::vec3(0, -1, -3));
    ssand.setScale(glm::vec3(20.0f, 0.0f, 12.0f));
    ssand.setColor(0.965, 0.843, 0.69, 1);
    ssand.drawTexturedCube(grassTexture);

    Cube newCube(1, Material::Metal);
    newCube.setPosition(glm::vec3(1, 2, -3));
    newCube.setRotation(25.0f, glm::vec3(1.0f, 1.0f, 0.0f));
    newCube.setScale(glm::vec3(1.0f, 1.0f, 1.0f));
    newCube.setColor(1, 1, 0, 1);
    newCube.draw();

    Cube secCube(1, Material::Metal);
    secCube.setPosition(glm::vec3(2, 1, 1));
    secCube.setColor(0.4, 0.2, 0.6, 1);
    secCube.draw();

    Cube thrdCube(1, Material::Metal);
    thrdCube.setPosition(glm::vec3(0.5, 1, -1));
    thrdCube.setColor(0.4, 0.7, 0.6, 1);
    thrdCube.draw();

    Cube frthCube(1, Material::Metal);
    frthCube.setPosition(glm::vec3(3, 2, -2));
    frthCube.setColor(0.2, 0.9, 0.3, 1);
    frthCube.setScale(glm::vec3(1.0f, 2.0f, 1.0f));
    frthCube.setRotation(75.0f, glm::vec3(0.0f, 0.0f, 1.0f));
    frthCube.draw();

    Ball newBall(2, 100, 100, Material::Metal);
    newBall.setPosition(glm::vec3(-3, 2, 5));
    newBall.setScale(glm::vec3(1, 2, 1));
    newBall.setColor(1, 0, 1, 1);
    newBall.draw();

    Texture stoneTexture;
    stoneTexture.loadTexture("Textury/stone.jpg");
    Cube textureCube(1, Material::Stone);
    textureCube.setPosition(glm::vec3(0, 0, 0));
    textureCube.setColor(1, 1, 1, 1);
    textureCube.setScale(glm::vec3(1.0f, 2.0f, 1.0f));
    textureCube.drawTexturedCube(stoneTexture);

    Texture soccerTexture;
    soccerTexture.loadTexture("Textury/soccer.jpg");
    Ball secBall(0.4, 100, 100, Material::Metal);
    secBall.setPosition(glm::vec3(3, 2, 1));
    secBall.drawTexturedBall(soccerTexture);

    Ball thrdBall(0.5, 100, 100, Material::Metal);
    thrdBall.setPosition(glm::vec3(4, 1, 1));
    thrdBall.setColor(0, 0.5, 1, 1);
    thrdBall.draw();

    Ball frthBall(0.5, 100, 100, Material::Metal);
    frthBall.setPosition(glm::vec3(5.1, 1, -1));
    frthBall.setColor(0.5, 0.9, 0, 1);
    frthBall.draw();

    Cone newCone(0.5, 1.0f, 100, 100, Material::Metal);
    newCone.setPosition(glm::vec3(3, 3, 0));
    newCone.setColor(0.5, 0.9, 0, 1);
    newCone.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
    newCone.draw();

    if (isCursorCaptured) {
        glutWarpPointer(windowWidth / 2, windowHeight / 2);
    }

    glutSwapBuffers();
}

void Engine::reshape(int width, int height) {
    windowWidth = width;
    windowHeight = height;
    setupViewport();
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
    case 'f':
        if (!isFullscreen) {
            glutFullScreen();  // W³¹cz tryb pe³noekranowy
            isFullscreen = true;
        }
        else {
            glutPositionWindow(0, 0); // Przywróæ pozycjê okna
            reshape(windowWidth, windowWidth);
            isFullscreen = false;
        }
        break;
    case 'l':
        if (light.isEnabled()) {
            light.disable();
        }
        else {
            light.enable();
        }
        break;
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

void Engine::cleanUp() {
    // Sprz¹tanie pamiêci, zamkniêcie okna itp.
    glutDestroyWindow(glutGetWindow());
}

void Engine::timer(int value) {
    update();
    glutPostRedisplay(); // Przerysuj scenê
    glutTimerFunc(1000 / framesPerSecond, Engine::timer, 0); // Ponownie ustaw timer
}
