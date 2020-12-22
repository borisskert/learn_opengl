#include <cmath>
#include "OpenGl.h"


using namespace mygl;

OpenGl::OpenGl(
        unsigned int screenWidthInPixels,
        unsigned int screenHeightInPixels,
        std::vector<ElementBufferObject> models
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
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        throw RuntimeException("Failed to initialize GLAD");
    }
}


void OpenGl::initializeViewport(GLFWwindow *window) {
    glViewport(0, 0, screenWidth, screenHeight);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}


void OpenGl::processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


elementBuffer OpenGl::initializeElementBuffer(const ElementBufferObject &ebo) {
    unsigned int elementBuffer;
    glGenBuffers(1, &elementBuffer);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, ebo.indicesCount() * sizeof(unsigned int), ebo.getIndices(), GL_STATIC_DRAW);

    return elementBuffer;
}


void OpenGl::render() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}


void OpenGl::draw(
        vertexArray vertexArray,
        const ElementBufferObject &ebo
) {
    glBindVertexArray(vertexArray);
    glDrawElements(GL_TRIANGLES, ebo.indicesCount(), GL_UNSIGNED_INT, nullptr);
}


vertexArray OpenGl::initializeVertexArray(vertexBuffer vertexBuffer, const ElementBufferObject &ebo) {
    unsigned int vertexArrayObject;
    glGenVertexArrays(1, &vertexArrayObject);

    glBindVertexArray(vertexArrayObject);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, ebo.verticesCount() * sizeof(float), ebo.getVertices(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *) nullptr);
    glEnableVertexAttribArray(0);

    return vertexArrayObject;
}


DrawableElement OpenGl::toDrawable(const ElementBufferObject &ebo) {
    DrawableElement drawable;

    drawable.ebo = ebo;
    drawable.vb = initializeVertexBuffer();
    drawable.va = initializeVertexArray(drawable.vb, ebo);
    drawable.eb = initializeElementBuffer(ebo);

    return drawable;
}


void OpenGl::runEngine(
        GLFWwindow *window
) {
    shaderProgram shaderProgram = initializeShaderProgram();

    std::vector<DrawableElement> drawableElements;
    for (const ElementBufferObject &ebo : models) {
        DrawableElement drawable = toDrawable(ebo);
        drawableElements.push_back(drawable);
    }

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        render();

        updateGlobalColorOverTime(shaderProgram);

        glUseProgram(shaderProgram);

        for (const DrawableElement &drawableElement : drawableElements) {
            draw(drawableElement.va, drawableElement.ebo);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}


void OpenGl::updateGlobalColorOverTime(shaderProgram shaderProgram) const {
    float timeValue = glfwGetTime();
    float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
    int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
    glUseProgram(shaderProgram);
    glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
}


vertexBuffer OpenGl::initializeVertexBuffer() {
    unsigned int vertexBufferObject;
    glGenBuffers(1, &vertexBufferObject);

    return vertexBufferObject;
}


vertexShader OpenGl::initializeVertexShader() {
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    const char *vertexShaderSource = "#version 330 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = vec4(aPos, 1.0);\n"
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


fragmentShader OpenGl::initializeFragmentShader() {
    const char *fragmentShaderSource = "#version 330 core\n"
                                       "out vec4 FragColor;\n"
                                       "uniform vec4 ourColor;\n"
                                       "\n"
                                       "void main()\n"
                                       "{\n"
                                       "    FragColor = ourColor;\n"
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


shaderProgram OpenGl::initializeShaderProgram() {
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


void OpenGl::start() {
    initializeGlfwWindow();

    GLFWwindow *window = createGlfwWindow();

    initializeGlad();

    initializeViewport(window);

    runEngine(window);
}
