#include <iostream>
#include <gl_lib/OpenGl.h>
#include <gl_lib/Texture.h>
#include <gl_lib/TexturedRectangle.h>


// settings
const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;


int main() {
    std::vector<gl_lib::Drawable *> models;

    gl_lib::Texture containerTexture("assets/textures/container.jpg");

    gl_lib::TexturedRectangle texturedRectangle(
            glm::vec3(0.5f, 0.5f, 0.0f),
            glm::vec3(0.5f, -0.5f, 0.0f),
            glm::vec3(-0.5f, -0.5f, 0.0f),
            glm::vec3(-0.5f, 0.5f, 0.0f),
            glm::vec3(1.0f, 0.0f, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f),
            glm::vec3(0.0f, 0.0f, 1.0f),
            glm::vec3(1.0f, 1.0f, 0.0f),
            containerTexture
    );

    models.push_back(&texturedRectangle);

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
