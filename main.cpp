#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "src/RuntimeException.h"
#include "src/ShaderInitializationException.h"

typedef unsigned int vertexBuffer;
typedef unsigned int vertexArray;
typedef unsigned int vertexShader;
typedef unsigned int fragmentShader;
typedef unsigned int shaderProgram;

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
    GLFWwindow *window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "LearnOpenGL", nullptr, nullptr);
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

void render() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void draw(vertexBuffer vertexBuffer, shaderProgram shaderProgram, vertexArray vertexArray) {
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) nullptr);
    glEnableVertexAttribArray(0);

    glUseProgram(shaderProgram);

    glBindVertexArray(vertexArray);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

/**
 * Create and bind vertex array
 * @param vertexBuffer
 * @return
 */
vertexArray initializeVertexArray(unsigned int vertexBuffer) {
    unsigned int vertexArrayObject;
    glGenVertexArrays(1, &vertexArrayObject);

    glBindVertexArray(vertexArrayObject);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) nullptr);
    glEnableVertexAttribArray(0);

    return vertexArrayObject;
}

/**
 * render loop
 * @param window pointer to the window object
 */
void runEngine(
        GLFWwindow *window,
        vertexBuffer vertexBuffer,
        shaderProgram shaderProgram,
        vertexArray vertexArray
) {
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        render();

        draw(vertexBuffer, shaderProgram, vertexArray);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}

vertexBuffer initializeVertexBuffer() {
    unsigned int vertexBufferObject;
    glGenBuffers(1, &vertexBufferObject);

    return vertexBufferObject;
}

vertexShader initializeVertexShader() {
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    const char *vertexShaderSource = "#version 330 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\0";

    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    int success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    char infoLog[512];
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        throw ShaderInitializationException("ERROR::SHADER::VERTEX::COMPILATION_FAILED", infoLog);
    }

    return vertexShader;
}

fragmentShader initializeFragmentShader() {
    const char *fragmentShaderSource = "#version 330 core\n"
                                       "out vec4 FragColor;\n"
                                       "\n"
                                       "void main()\n"
                                       "{\n"
                                       "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                       "} ";

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    int success;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    char infoLog[512];
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        throw ShaderInitializationException("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED", infoLog);
    }

    return fragmentShader;
}

shaderProgram initializeShaderProgram() {
    vertexShader vertexShader = initializeVertexShader();
    fragmentShader fragmentShader = initializeFragmentShader();

    shaderProgram shaderProgram;
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
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
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

        vertexBuffer vertexBuffer = initializeVertexBuffer();
        shaderProgram shaderProgram = initializeShaderProgram();
        vertexArray vertexArray = initializeVertexArray(vertexBuffer);

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
