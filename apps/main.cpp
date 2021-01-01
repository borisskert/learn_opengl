#include <iostream>
#include <gl_lib/OpenGl.h>
#include <gl_lib/ModelAdapter.h>
#include <gl_lib/LightSource.h>
#include <gl_lib/Cube.h>
#include <gl_lib/Textured.h>
#include <gl_lib/DiffuseTextured.h>
#include <gl_lib/DiffuseAndSpecularTextured.h>


std::string assetsPath;


// settings
const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;


using namespace gl_lib;


Drawable *createTexturedCube(
        glm::vec3 position,
        float angle,
        Texture *first,
        Texture *second
) {
    gl_lib::Cube::Builder *cubeBuilder = Cube::builder()
            ->colorA(glm::vec3(0.0f, 0.0f, 1.0f))
            ->colorB(glm::vec3(1.0f, 0.0f, 0.0f))
            ->colorC(glm::vec3(0.0f, 1.0f, 0.0f))
            ->colorD(glm::vec3(0.0f, 1.0f, 1.0f))
            ->colorE(glm::vec3(1.0f, 1.0f, 0.0f))
            ->colorF(glm::vec3(1.0f, 0.0f, 1.0f))
            ->colorG(glm::vec3(1.0f, 1.0f, 1.0f))
            ->colorH(glm::vec3(0.5f, 1.0f, 0.5f));

    Cube cube = cubeBuilder->build();

    ModelAdapter::Builder *builder = ModelAdapter::builder();

    ModelAdapter adapter = builder
            ->model(new Cube(cube))
            ->position(position)
            ->angle(angle)
            ->build();

    Textured *texturedModel = new Textured(new ModelAdapter(adapter));
    texturedModel->addTexture(first);
    texturedModel->addTexture(second);

    return texturedModel;
}


Drawable *createDiffuseTexturedCube(
        glm::vec3 position,
        float angle,
        Texture *texture
) {
    gl_lib::Cube::Builder *cubeBuilder = Cube::builder()
            ->color(glm::vec3(1.0f));

    Cube cube = cubeBuilder->build();

    ModelAdapter::Builder *builder = ModelAdapter::builder();

    ModelAdapter adapter = builder
            ->model(new Cube(cube))
            ->position(position)
            ->angle(angle)
            ->build();

    DiffuseTextured *texturedModel = new DiffuseTextured(
            new ModelAdapter(adapter),
            texture
    );

    return texturedModel;
}

Drawable *createDiffuseAndSpecularTexturedCube(
        glm::vec3 position,
        float angle,
        Texture *diffuse,
        Texture *specular
) {
    gl_lib::Cube::Builder *cubeBuilder = Cube::builder()
            ->color(glm::vec3(1.0f));

    Cube cube = cubeBuilder->build();

    ModelAdapter::Builder *builder = ModelAdapter::builder();

    ModelAdapter adapter = builder
            ->model(new Cube(cube))
            ->position(position)
            ->angle(angle)
            ->build();

    gl_lib::DiffuseAndSpecularTextured *texturedModel = new DiffuseAndSpecularTextured(
            new ModelAdapter(adapter),
            diffuse,
            specular
    );

    return texturedModel;
}


Drawable *createMonoColoredCube(glm::vec3 color, glm::vec3 position, float angle) {
    Cube cube = Cube::builder()->color(color)->build();

    ModelAdapter adapter = ModelAdapter::builder()
            ->model(new Cube(cube))
            ->position(position)
            ->angle(angle)
            ->build();

    return new ModelAdapter(adapter);
}


Drawable *createColoredCube(glm::vec3 position, float angle) {
    Cube cube = Cube::builder()
            ->colorABCD(glm::vec3(1.0f, 0.0f, 0.0f))
            ->colorBAEF(glm::vec3(0.0f, 1.0f, 0.0f))
            ->colorBFGC(glm::vec3(0.0f, 0.0f, 1.0f))
            ->colorCGHD(glm::vec3(0.0f, 1.0f, 1.0f))
            ->colorEADH(glm::vec3(1.0f, 1.0f, 0.0f))
            ->colorFEHG(glm::vec3(1.0f, 0.0f, 1.0f))
            ->build();

    ModelAdapter adapter = ModelAdapter::builder()
            ->model(new Cube(cube))
            ->position(position)
            ->angle(angle)
            ->build();

    return new ModelAdapter(adapter);
}


std::vector<gl_lib::Drawable *> buildCubes() {
    std::vector<gl_lib::Drawable *> models;

    auto *containerTexture = new Texture(assetsPath + std::string("/textures/container.jpg"));
    auto *awesomefaceTexture = new Texture(assetsPath + std::string("/textures/awesomeface.png"));
    auto *wallTexture = new Texture(assetsPath + std::string("/textures/wall.jpg"));
    auto *diffuseTexture = new Texture(assetsPath + std::string("/textures/container2.png"));
    auto *specularTexture = new Texture(assetsPath + std::string("/textures/container2_specular.png"));

    models.push_back(createTexturedCube(glm::vec3(0.0f), 0.0f, containerTexture, awesomefaceTexture));

    models.push_back(createTexturedCube(glm::vec3(2.0f, 5.0f, -15.0f), 20.0f, containerTexture, containerTexture));

    models.push_back(createTexturedCube(glm::vec3(-1.5f, -2.2f, -2.5f), 40.0f, wallTexture, wallTexture));

    models.push_back(
            createTexturedCube(glm::vec3(-3.8f, -2.0f, -12.3f), 60.0f, awesomefaceTexture, awesomefaceTexture));

    models.push_back(createTexturedCube(glm::vec3(2.4f, -0.4f, -3.5f), 70.0f, containerTexture, wallTexture));

    models.push_back(createTexturedCube(glm::vec3(-1.7f, 3.0f, -7.5f), 80.0f, wallTexture, containerTexture));

    models.push_back(createTexturedCube(glm::vec3(1.3f, -2.0f, -2.5f), 100.0f, wallTexture, awesomefaceTexture));

    models.push_back(createTexturedCube(glm::vec3(1.5f, 2.0f, -2.5f), 120.0f, containerTexture, wallTexture));

    models.push_back(createColoredCube(glm::vec3(2.5f, 0.2f, -1.5f), 140.0f));

    models.push_back(createMonoColoredCube(glm::vec3(1.0f), glm::vec3(-1.3f, 1.0f, -1.5f), 160.0f));

    models.push_back(createDiffuseTexturedCube(glm::vec3(-3.0f, 0.0f, -2.0f), 0.0f, diffuseTexture));

    models.push_back(
            createDiffuseAndSpecularTexturedCube(
                    glm::vec3(-5.0f, 2.0f, -4.0f),
                    0.0f,
                    diffuseTexture, specularTexture
            ));

    return models;
}


int main(int argc, char **argv) {
    for (int index = 0; index < argc; index++) {
        std::string argument(argv[index]);

        if (argument == "--assets-path") {
            assetsPath = argv[index + 1];
        }
    }

    std::vector<gl_lib::Drawable *> models = buildCubes();

    LightSource light(
            glm::vec3(0.0f),
            glm::vec3(1.0f, 0.9569, 0.5176),
            1.0f,
            glm::vec3(0.1f)
    );

    try {
        gl_lib::OpenGl openGl(SCREEN_WIDTH, SCREEN_HEIGHT, models, light);
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
