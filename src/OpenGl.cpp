#include <gl_lib/OpenGl.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <utility>
#include <gl_lib/ContextContainer.h>
#include <gl_lib/LightSource.h>
#include <gl_lib/FlashLight.h>


using namespace gl_lib;

OpenGl::OpenGl(
        unsigned int screenWidthInPixels, unsigned int screenHeightInPixels,
        Game *game
) : screenHeight(screenHeightInPixels),
    screenWidth(screenWidthInPixels),
    game(game) {}


void OpenGl::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}


void OpenGl::initializeGlfwWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}


GLFWwindow *OpenGl::createGlfwWindow() {
    GLFWwindow *window = glfwCreateWindow(screenWidth, screenHeight, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr) {
        glfwTerminate();
        throw RuntimeException("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(window);

    return window;
}


void OpenGl::initializeGlad() {
    initializeGladEnvironment();
}


void OpenGl::initializeViewport(GLFWwindow *window) {
    glViewport(0, 0, screenWidth, screenHeight);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}


void OpenGl::clear() {
    glm::vec3 backgroundColor = glm::vec3(0.0f);
    for (LightSource *light : game->getLights()) {
        backgroundColor += light->getBackgroundColor();
    }

    glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


ContextContainer OpenGl::createContext() {
    ContextContainer contextContainer;

    for (Drawable *drawable : game->getObjects()) {
        Context context{};

        context.shader = new Shader();
        context.buffer = new OpenGlBuffer();

        contextContainer.store(drawable, context);
    }

    for (LightSource *light : game->getLights()) {
        Context context = createLightContext();
        contextContainer.store(light, context);
    }

    return contextContainer;
}

Context OpenGl::createLightContext() const {
    Context model{};

    model.shader = new Shader();
    model.buffer = new OpenGlBuffer();
    return model;
}


void OpenGl::runEngine(
        GLFWwindow *window
) {
    glEnable(GL_DEPTH_TEST);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    mousePosition = new MousePosition(screenWidth, screenHeight);
    mouseInputAdapter = new MouseInputAdapter(window);
    mouseInputAdapter->registerCallback(this);

    game->initialize(&watch, &camera);

    ContextContainer contexts = createContext();
    prepareContexts(contexts);
    initializeContexts(contexts);

    while (!glfwWindowShouldClose(window)) {
        watch.startFrame();

        game->processInput(window);

        game->update();

        clear();

        draw(contexts);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}


void OpenGl::draw(ContextContainer &contexts) {
    for (Drawable *drawable : contexts.getDrawables()) {
        Context context = contexts.getFor(drawable);

        updateViewProjection(context.shader);

        drawable->update(&context);

        for (LightSource *light : game->getLights()) {
            light->renderLight(&context);
        }

        drawable->draw(&context);
    }
}


void OpenGl::initializeContexts(ContextContainer &contexts) {
    for (Drawable *drawable : contexts.getDrawables()) {
        Context context = contexts.getFor(drawable);

        updateViewProjection(context.shader);

        drawable->initialize(&context);
    }
}


void OpenGl::prepareContexts(ContextContainer &contexts) {
    for (Drawable *drawable : contexts.getDrawables()) {
        Context context = contexts.getFor(drawable);

        for (LightSource *lightSource : game->getLights()) {
            lightSource->prepareLight(&context);
        }

        drawable->prepare(&context);
    }
}


void OpenGl::updateViewProjection(Shader *shader) {
    shader->use();
    shader->setMat4("view", camera.getView());
    shader->setVec3("viewPos", camera.getPosition());

    glm::mat4 projection = glm::perspective(
            glm::radians(fieldOfView),
            (float) screenWidth / (float) screenHeight,
            0.1f,
            100.0f
    );

    shader->setMat4("projection", projection);
}


void OpenGl::start() {
    initializeGlfwWindow();

    GLFWwindow *window = createGlfwWindow();

    initializeGlad();

    initializeViewport(window);

    runEngine(window);
}


void OpenGl::onMouseMove(GLFWwindow *window, double x, double y) {
    mousePosition->update(glm::vec2(x, y));

    const float sensitivity = 0.1f;
    glm::vec2 offset = mousePosition->getOffset();

    camera.rotate(offset * sensitivity);
}


void OpenGl::onMouseScroll(GLFWwindow *window, double x, double y) {
    fieldOfView -= (float) y;

    if (fieldOfView < 1.0f)
        fieldOfView = 1.0f;
    if (fieldOfView > 45.0f)
        fieldOfView = 45.0f;

    std::cout << fieldOfView << std::endl;
}
