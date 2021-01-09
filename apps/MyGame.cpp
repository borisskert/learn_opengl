#include <gl_lib/Texture.h>
#include <gl_lib/Cube.h>
#include <gl_lib/ModelAdapter.h>
#include <gl_lib/SimpleColored.h>
#include <gl_lib/MovingInOrbit.h>
#include <gl_lib/Rotating.h>

#include <utility>
#include <gl_lib/Textured.h>
#include <gl_lib/DiffuseAndSpecularTextured.h>
#include <gl_lib/DiffuseTextured.h>
#include <gl_lib/PointLight.h>
#include <gl_lib/DirectionalLight.h>
#include "MyGame.h"


using namespace gl_lib;

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

    Drawable *drawable = new ModelAdapter(adapter);

    drawable = new SimpleColored(drawable);

    drawable = new MovingInOrbit(drawable, 2.1101f, glm::vec2(2.01f, 0.5f), glm::vec3(0.0f), 12.0f);

    drawable = new Rotating(
            drawable,
            angle,
            0.10f,
            glm::vec3(0.0f, 1.0f, 0.0f)
    );

    return drawable;
}


Drawable *createOrbitingMonoColoredCube(glm::vec3 color, glm::vec3 position, float angle) {
    Cube cube = Cube::builder()->color(color)->build();

    ModelAdapter adapter = ModelAdapter::builder()
            ->model(new Cube(cube))
            ->position(position)
            ->angle(angle)
            ->build();

    Drawable *drawable = new ModelAdapter(adapter);

    drawable = new SimpleColored(drawable);

    drawable = new MovingInOrbit(drawable, .1101f, glm::vec2(5.01f, 1.5f), glm::vec3(0.0f), 10.0f);

    drawable = new Rotating(
            drawable,
            angle,
            2.0f,
            glm::vec3(0.0f, 1.0f, 0.0f)
    );

    return drawable;
}


Drawable *createStaticMonoColoredCube(glm::vec3 color, glm::vec3 position, float angle) {
    Cube cube = Cube::builder()->color(color)->build();

    ModelAdapter adapter = ModelAdapter::builder()
            ->model(new Cube(cube))
            ->position(position)
            ->angle(angle)
            ->build();

    Drawable *drawable = new ModelAdapter(adapter);

    drawable = new SimpleColored(drawable);

    return drawable;
}


Drawable *createTexturedCube(
        glm::vec3 position,
        float angle,
        Texture *first,
        Texture *second
) {
    Cube::Builder *cubeBuilder = Cube::builder()
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
    Cube::Builder *cubeBuilder = Cube::builder()
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
    Cube::Builder *cubeBuilder = Cube::builder()
            ->color(glm::vec3(1.0f));

    Cube cube = cubeBuilder->build();

    ModelAdapter::Builder *builder = ModelAdapter::builder();

    ModelAdapter adapter = builder
            ->model(new Cube(cube))
            ->position(position)
            ->angle(angle)
            ->build();

    Drawable *drawable = new DiffuseAndSpecularTextured(
            new ModelAdapter(adapter),
            diffuse,
            specular
    );

    drawable = new MovingInOrbit(drawable, .0801f, glm::vec2(2.51f, 2.5f), glm::vec3(0.0f), 20.0f);

    drawable = new Rotating(
            drawable,
            angle,
            1.5f,
            glm::vec3(0.0f, 1.0f, 0.0f)
    );

    return drawable;
}


std::vector<Drawable *> buildCubes(const std::string &assetsPath) {
    std::vector<Drawable *> models;

    auto *containerTexture = new Texture(assetsPath + std::string("/textures/container.jpg"));
    auto *awesomefaceTexture = new Texture(assetsPath + std::string("/textures/awesomeface.png"));
    auto *wallTexture = new Texture(assetsPath + std::string("/textures/wall.jpg"));
    auto *diffuseTexture = new Texture(assetsPath + std::string("/textures/container2.png"));
    auto *specularTexture = new Texture(assetsPath + std::string("/textures/container2_specular.png"));

    models.push_back(createTexturedCube(glm::vec3(3.0f), 3.0f, containerTexture, awesomefaceTexture));

    models.push_back(createTexturedCube(glm::vec3(2.0f, 5.0f, -15.0f), 20.0f, containerTexture, containerTexture));

    models.push_back(createTexturedCube(glm::vec3(-1.5f, -2.2f, -2.5f), 40.0f, wallTexture, wallTexture));

    models.push_back(
            createTexturedCube(glm::vec3(-3.8f, -2.0f, -12.3f), 60.0f, awesomefaceTexture, awesomefaceTexture));

    models.push_back(
            createTexturedCube(glm::vec3(15.8f, 3.0f, -82.3f), 60.0f, awesomefaceTexture, awesomefaceTexture));

    models.push_back(createTexturedCube(glm::vec3(2.4f, -0.4f, -3.5f), 70.0f, containerTexture, wallTexture));

    models.push_back(createTexturedCube(glm::vec3(-1.7f, 3.0f, -7.5f), 80.0f, wallTexture, containerTexture));

    models.push_back(createTexturedCube(glm::vec3(1.3f, -2.0f, -2.5f), 100.0f, wallTexture, awesomefaceTexture));

    models.push_back(createTexturedCube(glm::vec3(1.5f, 2.0f, -2.5f), 120.0f, containerTexture, wallTexture));

    models.push_back(createColoredCube(glm::vec3(0.0f), 140.0f));

    models.push_back(createOrbitingMonoColoredCube(glm::vec3(1.0f), glm::vec3(0.0f), 160.0f));
    models.push_back(createStaticMonoColoredCube(glm::vec3(1.0f), glm::vec3(0.0f, 0.0f, -30), 160.0f));

    models.push_back(createDiffuseTexturedCube(glm::vec3(-3.0f, 0.0f, -2.0f), 0.0f, diffuseTexture));

    models.push_back(
            createDiffuseAndSpecularTexturedCube(
                    glm::vec3(-5.0f, 2.0f, -4.0f),
                    0.0f,
                    diffuseTexture, specularTexture
            ));

    return models;
}


std::vector<LightSource *> createLights() {
    std::vector<LightSource *> lightSources;

    LightSource *light = new PointLight(
            glm::vec3(0.0f),
            glm::vec3(1.0f, 0.9569, 0.5176),
            1.0f,
            glm::vec3(0.1f)
    );

    lightSources.push_back(light);

    LightSource *light2 = new PointLight(
            glm::vec3(2.0f, 2.0f, 2.0f),
            glm::vec3(1.0f, 0.9569, 0.5176),
            1.0f,
            glm::vec3(0.1f)
    );

    lightSources.push_back(light2);

    LightSource *light3 = new PointLight(
            glm::vec3(16.0f, 0.0f, -80.3f),
            glm::vec3(1.0f, 0.9569, 0.5176),
            1.0f,
            glm::vec3(0.1f)
    );

    lightSources.push_back(light3);

    LightSource *directionalLight = new DirectionalLight(
            glm::vec3(-1.0f, -2.0f, -.5f),
            glm::vec3(0.1f),
            glm::vec3(0.7f),
            glm::vec3(1.0f)
    );
    lightSources.push_back(directionalLight);

    return lightSources;
}


MyGame::MyGame(const std::string &assetsPath)
        : objects(buildCubes(assetsPath)),
          lights(createLights()),
          movedLight((PointLight *) lights[1]) {}


std::vector<Drawable *> MyGame::getObjects() {
    return objects;
}


std::vector<LightSource *> MyGame::getLights() {
    return lights;
}


void updateRandomLight(PointLight *lightSource, const Watch *watch) {
    lightSource->setPosition(
            glm::vec3(5.0f * cos(watch->getCurrent() / 2), 5.0f * sin(watch->getCurrent() / 2), 0.0f));

    glm::vec3 lightColor;
    lightColor.x = sin(glfwGetTime() * 2.0f);
    lightColor.y = sin(glfwGetTime() * 0.7f);
    lightColor.z = sin(glfwGetTime() * 1.3f);

    lightSource->setColor(lightColor);
}


void MyGame::update(const Watch *watch) {
    updateRandomLight(movedLight, watch);
}
