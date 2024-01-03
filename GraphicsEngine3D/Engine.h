#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "GeometryDrawer.h"
#include "PrimitiveDrawer.h"
#include "IndexedCube.h"
#include "Camera.h"

class Engine {
public:
    Engine(int argc, char** argv);
    ~Engine();

    void init(int width, int height, bool fullscreen, const char* name);
    void run();
    void shutdown();

    static void render();
    static void reshape(int width, int height);
    static void keyboard(unsigned char key, int x, int y);
    static void keyboardUp(unsigned char key, int x, int y);
    static void timer(int value);
    static void mouseMotion(int x, int y);

private:
    static Camera camera;
    static int windowWidth;
    static int windowHeight;
    static int framesPerSecond;
    bool isFullscreen;
    bool isRunning;
    const char* windowTitle;
    static bool isCursorCaptured;
    static bool isWKeyPressed;
    static bool isSKeyPressed;
    static bool isAKeyPressed;
    static bool isDKeyPressed;

    void initGL();
    static void setupViewport();
    void handleInput();
    void update();
    void cleanUp();
};