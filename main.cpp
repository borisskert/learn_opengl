#include <iostream>
#include "gl_lib/src/OpenGl.h"


// settings
const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;


int main() {
    try {
        mygl::OpenGl openGl(SCREEN_WIDTH, SCREEN_HEIGHT);
        openGl.start();
    }
    catch (const ShaderInitializationException &exception) {
        std::cout << exception.getMessage() << exception.getInfoLog() << std::endl;
        return -1;
    }
    catch (const RuntimeException &exception) {
        std::cout << "Error occurred: " << exception.getMessage() << std::endl;
        return -1;
    }

    return 0;
}
