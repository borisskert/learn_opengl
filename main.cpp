#include <iostream>
#include "gl_lib/src/OpenGl.h"
#include "gl_lib/src/Rectangle.h"
#include "gl_lib/src/Triangle.h"


// settings
const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;


int main() {
    VertexModels models;

    Rectangle rectangleOne = Rectangle(
            Point(0.5f, 0.5f, 0.0f),  // top right
            Point(0.5f, 0.0f, 0.0f),  // bottom right
            Point(0.0f, 0.0f, 0.0f),  // bottom left
            Point(0.0f, 0.5f, 0.0f)  // top left
    );

    models.add(&rectangleOne);

    Rectangle rectangleTwo = Rectangle(
            Point(0.0f, 0.0f, 0.0f),  // top right
            Point(0.0f, -0.5f, 0.0f),  // bottom right),
            Point(-0.5f, -0.5f, 0.0f),  // bottom left),
            Point(-0.5f, 0.0f, 0.0f)   // top left)
    );

    models.add(&rectangleTwo);

    Triangle triangle = Triangle(
            Point(0.5f, -0.5f, 0.0f),
            Point(0.0f, -0.5f, 0.0f),
            Point(0.5f, 0.0f, 0.0f)
    );

    models.add(&triangle);

    try {
        mygl::OpenGl openGl(SCREEN_WIDTH, SCREEN_HEIGHT, models);
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
