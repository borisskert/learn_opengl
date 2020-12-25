#include <gl_lib/gl_lib.h>
#include <gl_lib/ShaderInitializationException.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace gl_lib {
    vertexBuffer createVertexBuffer() {
        unsigned int vertexBufferObject;
        glGenBuffers(1, &vertexBufferObject);

        return vertexBufferObject;
    }


    vertexArray createVertexArray() {
        unsigned int vertexArrayObject;
        glGenVertexArrays(1, &vertexArrayObject);

        return vertexArrayObject;
    }


    elementBuffer createElementBuffer() {
        unsigned int elementBufferObject;
        glGenBuffers(1, &elementBufferObject);

        return elementBufferObject;
    }


    void bindElementBuffer(elementBuffer elementBufferObject) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
    }


    unsigned int compileVertexShader(const char *shaderSource) {
        return compileShader(shaderSource, GL_VERTEX_SHADER);
    }


    unsigned int compileFragmentShader(const char *shaderSource) {
        return compileShader(shaderSource, GL_FRAGMENT_SHADER);
    }


    unsigned int compileShader(const char *shaderSource, unsigned int shaderType) {
        unsigned int compiledShader;
        compiledShader = glCreateShader(shaderType);

        glShaderSource(compiledShader, 1, &shaderSource, nullptr);
        glCompileShader(compiledShader);

        int success;
        glGetShaderiv(compiledShader, GL_COMPILE_STATUS, &success);

        char infoLog[512];
        if (!success) {
            glGetShaderInfoLog(compiledShader, 512, nullptr, infoLog);
            throw ShaderInitializationException("ERROR::SHADER::COMPILATION_FAILED", infoLog);
        }

        return compiledShader;
    }


    shaderProgram initializeShaderProgram(vertexShader vertexShader, fragmentShader fragmentShader) {
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


    std::string readFileContent(const char *filePath) {
        std::string fileContent;
        std::ifstream fileStream;

        fileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try {
            fileStream.open(filePath);
            std::stringstream contentStream;
            contentStream << fileStream.rdbuf();
            fileStream.close();
            fileContent = contentStream.str();
        } catch (std::ifstream::failure e) {
            throw RuntimeException("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ");
        }

        return fileContent.c_str();
    }


    void drawElements(vertexArray vertexArrayObject, unsigned int indicesCount) {
        glBindVertexArray(vertexArrayObject);
        glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, nullptr);
    }


    void initializeGladEnvironment() {
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            throw RuntimeException("Failed to initialize GLAD");
        }
    }
}
