#include <gl_lib/OpenGl.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <gl_lib/ContextContainer.h>
#include <gl_lib/LightSource.h>


using namespace gl_lib;

OpenGl::OpenGl(unsigned int screenWidthInPixels, unsigned int screenHeightInPixels, std::vector<Drawable *> models,
               TextureUnit unit, gl_lib::LightSource lightSource)
        : screenHeight(screenHeightInPixels),
          screenWidth(screenWidthInPixels),
          models(std::move(models)),
          textureUnit(unit),
          lightSource(lightSource) {}


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


void OpenGl::processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    else {
        const float cameraSpeed = 10.0 * watch.getDelta();

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            camera.forward(cameraSpeed);
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            camera.backward(cameraSpeed);
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            camera.strafeLeft(cameraSpeed);
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            camera.strafeRight(cameraSpeed);
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
            camera.goUp(cameraSpeed);
        if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
            camera.goDown(cameraSpeed);
    }
}


void OpenGl::clear() {
    glm::vec3 backgroundColor = lightSource.getStrength() * 0.05f * lightSource.getColor();

    glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


ContextContainer OpenGl::createContext(const std::vector<Drawable *> &drawables) {
    ContextContainer context;

    for (Drawable *drawable : drawables) {
        Context model{};

        model.shader = new Shader(
                "assets/shader/vertex.shader",
                "assets/shader/fragment.shader"
        );
        model.buffer = new OpenGlBuffer();
        model.textures = &textureUnit;

        context.store(drawable, model);
    }

    Context model = createLightContext();
    context.store(&lightSource, model);

    return context;
}

Context OpenGl::createLightContext() const {
    Context model{};

    model.shader = new Shader(
            "assets/shader/lightVertex.shader",
            "assets/shader/lightFragment.shader"
    );
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


    ContextContainer contexts = createContext(models);

    for (Drawable *drawable : contexts.getDrawables()) {
        Context context = contexts.getFor(drawable);

        context.shader->use();
        context.shader->setMat4("view", camera.getView());
        context.shader->setVec3("viewPos", camera.getPosition());

        glm::mat4 projection;
        projection = glm::perspective(glm::radians(fieldOfView), (float) screenWidth / (float) screenHeight, 0.1f, 100.0f);
        context.shader->setMat4("projection", projection);

        drawable->initialize(&context);
    }

    while (!glfwWindowShouldClose(window)) {
        watch.startFrame();

        processInput(window);

        clear();

        lightSource.setPosition(glm::vec3(5.0f * cos(watch.getCurrent() / 2), 5.0f * sin(watch.getCurrent() / 2), 0.0f));

        for (Drawable *drawable : contexts.getDrawables()) {
            Context context = contexts.getFor(drawable);

            context.shader->use();
            context.shader->setMat4("view", camera.getView());
            context.shader->setVec3("viewPos", camera.getPosition());

            glm::mat4 projection = glm::perspective(glm::radians(fieldOfView), (float) screenWidth / (float) screenHeight, 0.1f, 100.0f);
            context.shader->setMat4("projection", projection);

            drawable->update(&context);

            lightSource.renderLight(&context);
            drawable->draw(&context);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}


void OpenGl::start() {
    initializeGlfwWindow();

    GLFWwindow *window = createGlfwWindow();

    initializeGlad();

    initializeViewport(window);

    runEngine(window);
}


void OpenGl::onMouseMove(GLFWwindow* window, double x, double y) {
    mousePosition->update(glm::vec2(x, y));

    const float sensitivity = 0.1f;
    glm::vec2 offset = mousePosition->getOffset();
    camera.rotate(offset * sensitivity);
}


void OpenGl::onMouseScroll(GLFWwindow *window, double x, double y) {
    fieldOfView -= (float)y;
    if (fieldOfView < 1.0f)
        fieldOfView = 1.0f;
    if (fieldOfView > 45.0f)
        fieldOfView = 45.0f;

    std::cout << fieldOfView << std::endl;
}
