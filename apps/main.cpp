#include <iostream>
#include <gl_lib/OpenGl.h>
#include <gl_lib/ModelAdapter.h>
#include <gl_lib/LightSource.h>
#include <gl_lib/Cube.h>
#include <gl_lib/Textured.h>
#include <gl_lib/DiffuseTextured.h>
#include <gl_lib/DiffuseAndSpecularTextured.h>
#include <gl_lib/Rotating.h>
#include <gl_lib/MovingInOrbit.h>
#include <gl_lib/SimpleColored.h>
#include "MyGame.h"


// settings
const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;


using namespace gl_lib;


std::string readAssetsPath(int argc, char *const *argv) {
    std::string assetsPath;

    for (int index = 0; index < argc; index++) {
        std::string argument(argv[index]);

        if (argument == "--assets-path") {
            assetsPath = argv[index + 1];
        }
    }

    return assetsPath;
}

int main(int argc, char **argv) {
    std::string assetsPath = readAssetsPath(argc, argv);

    MyGame *game = new MyGame(assetsPath);

    try {
        gl_lib::OpenGl openGl(SCREEN_WIDTH, SCREEN_HEIGHT, game);
        openGl.start();
    }
    catch (const gl_lib::ShaderInitializationException &exception) {
        std::cout << exception.getMessage() << std::endl << exception.getInfoLog() << std::endl;
        return -1;
    }
    catch (const gl_lib::RuntimeException &exception) {
        std::cout << "Error occurred: " << exception.getMessage() << std::endl;
        return -1;
    }

    return 0;
}
