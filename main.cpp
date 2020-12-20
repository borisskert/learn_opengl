#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "src/RuntimeException.h"

// settings
const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;

/**
 * glfw: whenever the window size changed (by OS or user resize) this callback function executes
 * @param window pointer to the window object
 * @param width the screen width in pixels
 * @param height the screen height in pixels
 */
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

/**
 * glfw: initialize and configure
 */
void initializeGlfwWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

/**
 * glfw window creation
 * @return pointer to the created window object
 */
GLFWwindow *createGlfwWindow() {
    GLFWwindow *window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == nullptr) {
        glfwTerminate();
        throw RuntimeException("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(window);

    return window;
}

/**
 * glad: load all OpenGL function pointers
 */
void initializeGlad() {
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        throw RuntimeException("Failed to initialize GLAD");
    }
}

void initializeViewport(GLFWwindow *window) {
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

/**
 * process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
 * @param window pointer to the window object
 */
void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

/**
 * render loop
 * @param window pointer to the window object
 */
void runEngine(GLFWwindow *window) {
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}

int main() {
    try {
        initializeGlfwWindow();

        GLFWwindow *window = createGlfwWindow();

        initializeGlad();

        initializeViewport(window);

        runEngine(window);
    }
    catch (const RuntimeException &exception) {
        std::cout << "Error occurred: " << exception.getMessage() << std::endl;
        return -1;
    }

    return 0;
}
