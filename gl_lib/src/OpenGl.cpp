#include "OpenGl.h"


using namespace mygl;

OpenGl::OpenGl(
        unsigned int screenWidthInPixels,
        unsigned int screenHeightInPixels,
        VertexModels models
)
        : screenHeight(screenHeightInPixels),
          screenWidth(screenWidthInPixels),
          vertexModels(models) {}

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


elementBuffer OpenGl::initializeElementBuffer() {
    unsigned int elementBufferObject;
    glGenBuffers(1, &elementBufferObject);

    ElementBufferObject eob = vertexModels.toElementBufferObject();

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, eob.indicesCount() * sizeof(unsigned int), eob.getIndices(), GL_STATIC_DRAW);

    return elementBufferObject;
}


void OpenGl::render() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}


void OpenGl::draw(
        vertexBuffer vertexBuffer,
        shaderProgram shaderProgram,
        vertexArray vertexArray,
        elementBuffer elementBuffer
) {
    ElementBufferObject eob = vertexModels.toElementBufferObject();

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, eob.verticesCount() * sizeof(float), eob.getVertices(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) nullptr);
    glEnableVertexAttribArray(0);

    glUseProgram(shaderProgram);

    glBindVertexArray(vertexArray);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
    glDrawElements(GL_TRIANGLES, eob.indicesCount(), GL_UNSIGNED_INT, nullptr);
}


vertexArray OpenGl::initializeVertexArray(unsigned int vertexBuffer) {
    unsigned int vertexArrayObject;
    glGenVertexArrays(1, &vertexArrayObject);

    glBindVertexArray(vertexArrayObject);

    ElementBufferObject eob = vertexModels.toElementBufferObject();

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, eob.verticesCount() * sizeof(float), eob.getVertices(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) nullptr);
    glEnableVertexAttribArray(0);

    return vertexArrayObject;
}


void OpenGl::runEngine(
        GLFWwindow *window,
        vertexBuffer vertexBuffer,
        shaderProgram shaderProgram,
        vertexArray vertexArray,
        elementBuffer elementBuffer
) {
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        render();

        draw(vertexBuffer, shaderProgram, vertexArray, elementBuffer);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
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


fragmentShader OpenGl::initializeFragmentShader() {
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

    vertexBuffer vertexBuffer = initializeVertexBuffer();
    shaderProgram shaderProgram = initializeShaderProgram();
    vertexArray vertexArray = initializeVertexArray(vertexBuffer);
    elementBuffer elementBuffer = initializeElementBuffer();

    runEngine(window, vertexBuffer, shaderProgram, vertexArray, elementBuffer);
}
