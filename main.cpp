#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "src/RuntimeException.h"
#include "src/ShaderInitializationException.h"

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

const float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
};

void draw(unsigned int vertexBuffer, unsigned int shaderProgram, unsigned int vertexArray) {
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    glUseProgram(shaderProgram);

    glBindVertexArray(vertexArray);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

unsigned int initializeVertexArray(unsigned int vertexBuffer) {
    unsigned int vertexArrayObject;
    glGenVertexArrays(1, &vertexArrayObject);

    glBindVertexArray(vertexArrayObject);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    return vertexArrayObject;
}

/**
 * render loop
 * @param window pointer to the window object
 */
void runEngine(
        GLFWwindow *window,
        unsigned int vertexBuffer,
        unsigned int shaderProgram,
        unsigned int vertexArray
) {
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        draw(vertexBuffer, shaderProgram, vertexArray);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}

unsigned int initializeVertexBuffer() {
    unsigned int vertexBufferObject;
    glGenBuffers(1, &vertexBufferObject);

    return vertexBufferObject;
}

unsigned int initializeVertexShader() {
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    const char *vertexShaderSource = "#version 330 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\0";

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    char infoLog[512];
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        throw ShaderInitializationException("ERROR::SHADER::VERTEX::COMPILATION_FAILED", infoLog);
    }

    return vertexShader;
}

unsigned int initializeFragmentShader() {
    const char *fragmentShaderSource = "#version 330 core\n"
                                       "out vec4 FragColor;\n"
                                       "\n"
                                       "void main()\n"
                                       "{\n"
                                       "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                       "} ";

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    int success;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    char infoLog[512];
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        throw ShaderInitializationException("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED", infoLog);
    }

    return fragmentShader;
}

unsigned int initializeShaderProgram() {
    unsigned int vertexShader = initializeVertexShader();
    unsigned int fragmentShader = initializeFragmentShader();

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    int success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    char infoLog[512];
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        throw ShaderInitializationException("ERROR::SHADER::PROGRAM::LINKING_FAILED", infoLog);
    }

    return shaderProgram;
}

int main() {
    try {
        initializeGlfwWindow();

        GLFWwindow *window = createGlfwWindow();

        initializeGlad();

        initializeViewport(window);

        unsigned int vertexBuffer = initializeVertexBuffer();
        unsigned int shaderProgram = initializeShaderProgram();
        unsigned int vertexArray = initializeVertexArray(vertexBuffer);


        runEngine(window, vertexBuffer, shaderProgram, vertexArray);
    }
    catch (const ShaderInitializationException &exception) {
        std::cout << exception.getMessage() << exception.getInfoLog() << std::endl;
        return -1;
    }
    catch (const RuntimeException &exception) {
        std::cout << "Error occurred: " << exception.getMessage() << std::endl;
        return -1;
    }

    return 0;
}
