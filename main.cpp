#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "src/RuntimeException.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void initializeGlfwWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // for MacOS
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

GLFWwindow *createGlfwWindow() {
    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == nullptr) {
        glfwTerminate();
        throw RuntimeException("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(window);

    return window;
}

void initializeGlad() {
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        throw RuntimeException("Failed to initialize GLAD");
    }
}

void initializeViewport(GLFWwindow *window) {
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void runEngine(GLFWwindow *window) {
    while (!glfwWindowShouldClose(window)) {
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
