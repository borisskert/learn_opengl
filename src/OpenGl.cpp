#include <gl_lib/OpenGl.h>


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


void OpenGl::render() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}


void OpenGl::runEngine(
        GLFWwindow *window
) {
    Shader shaderProgram(
            "shader/vertex.shader",
            "shader/fragment.shader"
    );

    for (Drawable *drawable : models) {
        drawable->initialize();
    }

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        render();

        shaderProgram.use();

        for (Drawable *drawable : models) {
            drawable->draw();
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
