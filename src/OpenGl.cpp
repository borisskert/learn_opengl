#include <gl_lib/OpenGl.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>


using namespace gl_lib;

OpenGl::OpenGl(
        unsigned int screenWidthInPixels,
        unsigned int screenHeightInPixels,
        std::vector<Drawable *> models
)
        : screenHeight(screenHeightInPixels),
          screenWidth(screenWidthInPixels),
          models(std::move(models)) {}


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
}


void OpenGl::clear() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


std::vector<ModelContext> createContexts(std::vector<Drawable*> drawables) {
    std::vector<ModelContext> contexts;

    for (Drawable *drawable : drawables) {
        ModelContext model{};
        model.drawable = drawable;
        model.shader = new Shader(
                "assets/shader/vertex.shader",
                "assets/shader/fragment.shader"
        );
        model.buffer = new OpenGlBuffer();

        contexts.push_back(model);
    }

    return contexts;
}


void OpenGl::runEngine(
        GLFWwindow *window
) {
    glEnable(GL_DEPTH_TEST);

    std::vector<ModelContext> contexts = createContexts(models);

    for (ModelContext context : contexts) {
        context.shader->use();
        glm::mat4 view = glm::mat4(1.0f);
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        context.shader->setMat4("view", view);

        glm::mat4 projection;
        projection = glm::perspective(glm::radians(45.0f), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
        context.shader->setMat4("projection", projection);

        context.drawable->initialize(context.shader);
    }

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        clear();

        for (ModelContext model : contexts) {
            model.shader->use();

            model.drawable->update(model.shader);
            model.drawable->draw();
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
