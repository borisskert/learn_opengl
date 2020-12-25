#ifndef MYFIRSTOPENGL_GL_LIB_H
#define MYFIRSTOPENGL_GL_LIB_H

#include <gl_lib/Typedefs.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>


namespace gl_lib {
    vertexBuffer createVertexBuffer();

    vertexArray createVertexArray();

    elementBuffer createElementBuffer();

    void bindElementBuffer(elementBuffer elementBufferObject);

    unsigned int compileVertexShader(const char *shaderSource);

    unsigned int compileFragmentShader(const char *shaderSource);

    unsigned int compileShader(const char *shaderSource, unsigned int shaderType);

    shaderProgram initializeShaderProgram(vertexShader vertexShader, fragmentShader fragmentShader);

    std::string readFileContent(const char *filePath);

    void drawElements(vertexArray vertexArrayObject, unsigned int  indicesCount);

    void initializeGladEnvironment();
}

#endif //MYFIRSTOPENGL_GL_LIB_H
