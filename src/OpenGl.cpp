#include <gl_lib/OpenGl.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <gl_lib/ContextContainer.h>
#include <gl_lib/Camera.h>


using namespace gl_lib;

OpenGl::OpenGl(
        unsigned int screenWidthInPixels, unsigned int screenHeightInPixels,
        std::vector<Drawable *> models,
        TextureUnit textureUnit
)
        : screenHeight(screenHeightInPixels),
          screenWidth(screenWidthInPixels),
          models(std::move(models)),
          textureUnit(textureUnit) {}


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
        const float cameraSpeed = 0.05f;

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            camera.forward(cameraSpeed);
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            camera.backward(cameraSpeed);
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            camera.strafeLeft(cameraSpeed);
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            camera.strafeRight(cameraSpeed);
    }
}


void OpenGl::clear() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
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

    return context;
}


void OpenGl::runEngine(
        GLFWwindow *window
) {
    glEnable(GL_DEPTH_TEST);

    ContextContainer contexts = createContext(models);

    for (Drawable *drawable : contexts.getDrawables()) {
        Context context = contexts.getFor(drawable);

        context.shader->use();
        context.shader->setMat4("view", camera.getView());

        glm::mat4 projection;
        projection = glm::perspective(glm::radians(45.0f), (float) screenWidth / (float) screenHeight, 0.1f, 100.0f);
        context.shader->setMat4("projection", projection);

        drawable->initialize(&context);
    }

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        clear();

        for (Drawable *drawable : contexts.getDrawables()) {
            Context context = contexts.getFor(drawable);

            context.shader->use();
            context.shader->setMat4("view", camera.getView());

            drawable->update(&context);
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
