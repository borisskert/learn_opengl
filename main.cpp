#include <iostream>
#include "gl_lib/src/OpenGl.h"
#include "gl_lib/src/Rectangle.h"
#include "gl_lib/src/Triangle.h"
#include "gl_lib/src/ColorfulTriangle.h"


// settings
const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;


int main() {
    std::vector<gl_lib::Drawable *> models;

    gl_lib::Rectangle rectangleOne = gl_lib::Rectangle(
            glm::vec3(0.5f, 0.5f, 0.0f),  // top right
            glm::vec3(0.5f, 0.0f, 0.0f),  // bottom right
            glm::vec3(0.0f, 0.0f, 0.0f),  // bottom left
            glm::vec3(0.0f, 0.5f, 0.0f)  // top left
    );

    models.push_back(&rectangleOne);

    gl_lib::Rectangle rectangleTwo = gl_lib::Rectangle(
            glm::vec3(0.0f, 0.0f, 0.0f),  // top right
            glm::vec3(0.0f, -0.5f, 0.0f),  // bottom right),
            glm::vec3(-0.5f, -0.5f, 0.0f),  // bottom left),
            glm::vec3(-0.5f, 0.0f, 0.0f)   // top left)
    );

    models.push_back(&rectangleTwo);

    gl_lib::Triangle triangleOne = gl_lib::Triangle(
            glm::vec3(0.5f, -0.5f, 0.0f),
            glm::vec3(0.0f, -0.5f, 0.0f),
            glm::vec3(0.5f, 0.0f, 0.0f)
    );

    models.push_back(&triangleOne);

    gl_lib::ColorfulTriangle triangleTwo = gl_lib::ColorfulTriangle(
            glm::vec3(-0.5f, 0.5f, 0.0f),
            glm::vec3(0.0f, 0.5f, 0.0f),
            glm::vec3(-0.5f, 0.0f, 0.0f),
            glm::vec3(1.0f, 0.0f, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f),
            glm::vec3(0.0f, 0.0f, 1.0f)
    );

    models.push_back(&triangleTwo);

    try {
        gl_lib::OpenGl openGl(SCREEN_WIDTH, SCREEN_HEIGHT, models);
        openGl.start();
    }
    catch (const gl_lib::ShaderInitializationException &exception) {
        std::cout << exception.getMessage() << exception.getInfoLog() << std::endl;
        return -1;
    }
    catch (const gl_lib::RuntimeException &exception) {
        std::cout << "Error occurred: " << exception.getMessage() << std::endl;
        return -1;
    }

    return 0;
}
