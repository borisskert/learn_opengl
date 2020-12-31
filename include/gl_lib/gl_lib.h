#ifndef LEARN_OPENGL_GL_LIB_H
#define LEARN_OPENGL_GL_LIB_H

#include <gl_lib/gl_lib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>


namespace gl_lib {
    typedef unsigned int vertexBuffer;
    typedef unsigned int vertexArray;
    typedef unsigned int vertexShader;
    typedef unsigned int fragmentShader;
    typedef unsigned int elementBuffer;
    typedef unsigned int shaderProgram;
    typedef unsigned int textureId;

    vertexBuffer createVertexBuffer();

    vertexArray createVertexArray();

    elementBuffer createElementBuffer();

    void bindElementBuffer(elementBuffer elementBufferObject);

    unsigned int compileVertexShader(const char *shaderSource);

    unsigned int compileFragmentShader(const char *shaderSource);

    unsigned int compileShader(const char *shaderSource, unsigned int shaderType);

    shaderProgram createShaderProgram();

    void initializeShaderProgram(shaderProgram shaderProgram);

    std::string readFileContent(const char *filePath);

    void drawElements(vertexArray vertexArrayObject, unsigned int indicesCount);

    void initializeGladEnvironment();

    textureId createTexture();
}

#endif //LEARN_OPENGL_GL_LIB_H
