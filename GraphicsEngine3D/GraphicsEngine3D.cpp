#pragma comment(lib, "freeglut.lib")

#include <GL/glew.h>
#include <iostream>
#include "Engine.h"

int main(int argc, char** argv)
{
    Engine engine(argc, argv);
    engine.init(1280, 720, false, "Example title");
    glutMainLoop();
    return 0;
}