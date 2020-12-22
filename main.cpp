#include <iostream>
#include "gl_lib/src/OpenGl.h"
#include "gl_lib/src/Rectangle.h"
#include "gl_lib/src/Triangle.h"


// settings
const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;


int main() {
    std::vector<ElementBufferObject> models;

    Rectangle rectangleOne = Rectangle(
            Point(0.5f, 0.5f, 0.0f),  // top right
            Point(0.5f, 0.0f, 0.0f),  // bottom right
            Point(0.0f, 0.0f, 0.0f),  // bottom left
            Point(0.0f, 0.5f, 0.0f)  // top left
    );

    models.push_back(rectangleOne.toElementBufferObject());

    Rectangle rectangleTwo = Rectangle(
            Point(0.0f, 0.0f, 0.0f),  // top right
            Point(0.0f, -0.5f, 0.0f),  // bottom right),
            Point(-0.5f, -0.5f, 0.0f),  // bottom left),
            Point(-0.5f, 0.0f, 0.0f)   // top left)
    );

    models.push_back(rectangleTwo.toElementBufferObject());

    Triangle triangleOne = Triangle(
            Point(0.5f, -0.5f, 0.0f),
            Point(0.0f, -0.5f, 0.0f),
            Point(0.5f, 0.0f, 0.0f)
    );

    models.push_back(triangleOne.toElementBufferObject());

    Triangle triangleTwo = Triangle(
            Point(-0.5f, 0.5f, 0.0f),
            Point(0.0f, 0.5f, 0.0f),
            Point(-0.5f, 0.0f, 0.0f)
    );

    models.push_back(triangleTwo.toElementBufferObject());

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
