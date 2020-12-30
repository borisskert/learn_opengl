#include <iostream>
#include <gl_lib/OpenGl.h>
#include <gl_lib/TextureUnit.h>
#include <gl_lib/Cube.h>
#include <gl_lib/LightSource.h>


// settings
const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;


std::vector<gl_lib::Drawable *> buildCubes() {
    std::vector<gl_lib::Drawable *> models;
    Cube::Builder *builder = Cube::builder();

    Cube cube = builder
            ->colorA(glm::vec3(0.0f, 0.0f, 1.0f))
            ->colorB(glm::vec3(1.0f, 0.0f, 0.0f))
            ->colorC(glm::vec3(0.0f, 1.0f, 0.0f))
            ->colorD(glm::vec3(0.0f, 1.0f, 1.0f))
            ->colorE(glm::vec3(1.0f, 1.0f, 0.0f))
            ->colorF(glm::vec3(1.0f, 0.0f, 1.0f))
            ->colorG(glm::vec3(1.0f, 1.0f, 1.0f))
            ->colorH(glm::vec3(0.5f, 1.0f, 0.5f))
            ->position(glm::vec3(0.0f, 0.0f, 0.0f))
            ->build();

    models.push_back(new Cube(cube));

    cube = builder
            ->position(glm::vec3(2.0f, 5.0f, -15.0f))
            ->angle(20.0f)
            ->build();

    models.push_back(new Cube(cube));

    cube = builder
            ->position(glm::vec3(-1.5f, -2.2f, -2.5f))
            ->angle(40.0f)
            ->build();

    models.push_back(new Cube(cube));

    cube = builder
            ->position(glm::vec3(-3.8f, -2.0f, -12.3f))
            ->angle(60.0f)
            ->build();

    models.push_back(new Cube(cube));

    cube = builder
            ->position(glm::vec3(2.4f, -0.4f, -3.5f))
            ->angle(70.0f)
            ->build();

    models.push_back(new Cube(cube));

    cube = builder
            ->position(glm::vec3(-1.7f, 3.0f, -7.5f))
            ->angle(80.0f)
            ->build();

    models.push_back(new Cube(cube));

    cube = builder
            ->position(glm::vec3(1.3f, -2.0f, -2.5f))
            ->angle(100.0f)
            ->build();

    models.push_back(new Cube(cube));

    cube = builder
            ->position(glm::vec3(1.5f, 2.0f, -2.5f))
            ->angle(120.0f)
            ->build();

    models.push_back(new Cube(cube));

    cube = builder
            ->position(glm::vec3(1.5f, 0.2f, -1.5f))
            ->angle(140.0f)
            ->build();

    models.push_back(new Cube(cube));

    cube = builder
            ->color(glm::vec3(1.0f))
            ->position(glm::vec3(-1.3f, 1.0f, -1.5f))
            ->angle(160.0f)
            ->build();

    models.push_back(new Cube(cube));

    return models;
}

int main() {
    gl_lib::Texture containerTexture("assets/textures/container.jpg");
    gl_lib::Texture awesomefaceTexture("assets/textures/awesomeface.png");


    gl_lib::TextureUnit textureUnit;
    textureUnit.addTexture(&containerTexture);
    textureUnit.addTexture(&awesomefaceTexture);

    std::vector<gl_lib::Drawable *> models = buildCubes();

    LightSource light(
            glm::vec3(1.2f, 1.0f, -30.0f),
            glm::vec3(1.0f, 0.9569, 0.5176),
            0.85f,
            glm::vec3(0.55f)
    );

    try {
        gl_lib::OpenGl openGl(SCREEN_WIDTH, SCREEN_HEIGHT, models, textureUnit, light);
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
