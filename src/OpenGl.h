#ifndef MYFIRSTOPENGL_OPENGL_H
#define MYFIRSTOPENGL_OPENGL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "RuntimeException.h"
#include "ShaderInitializationException.h"

typedef unsigned int vertexBuffer;
typedef unsigned int vertexArray;
typedef unsigned int vertexShader;
typedef unsigned int fragmentShader;
typedef unsigned int elementBuffer;
typedef unsigned int shaderProgram;

namespace mygl {

    const float vertices[] = {
            0.5f, 0.5f, 0.0f,  // top right
            0.5f, 0.0f, 0.0f,  // bottom right
            0.0f, 0.0f, 0.0f,  // bottom left
            0.0f, 0.5f, 0.0f,   // top left

            0.0f, 0.0f, 0.0f,  // top right
            0.0f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
            -0.5f, 0.0f, 0.0f   // top left
    };

    const unsigned int indices[] = {
            0, 1, 3,   // first triangle
            1, 2, 3,    // second triangle

            4, 5, 7,   // first triangle
            5, 6, 7    // second triangle
    };


    class OpenGl {
    private:
        unsigned int screenWidth;
        unsigned int screenHeight;

    public:
        explicit OpenGl(
                unsigned int screenWidthInPixels,
                unsigned int screenHeightInPixels
        );

        /**
         * glfw: whenever the window size changed (by OS or user resize) this callback function executes
         * @param window pointer to the window object
         * @param width the screen width in pixels
         * @param height the screen height in pixels
         */
        static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

        /**
         * glfw: initialize and configure
         */
        void initializeGlfwWindow();

        /**
         * glfw window creation
         * @return pointer to the created window object
         */
        GLFWwindow *createGlfwWindow();

        /**
         * glad: load all OpenGL function pointers
         */
        void initializeGlad();

        void initializeViewport(GLFWwindow *window);

        /**
         * process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
         * @param window pointer to the window object
         */
        void processInput(GLFWwindow *window);

        elementBuffer initializeElementBuffer();

        void render();

        void draw(
                vertexBuffer vertexBuffer,
                shaderProgram shaderProgram,
                vertexArray vertexArray,
                elementBuffer elementBuffer
        );

        /**
         * Create and bind vertex array
         * @param vertexBuffer
         * @return
         */
        vertexArray initializeVertexArray(unsigned int vertexBuffer);

        /**
         * render loop
         * @param window pointer to the window object
         */
        void runEngine(
                GLFWwindow *window,
                vertexBuffer vertexBuffer,
                shaderProgram shaderProgram,
                vertexArray vertexArray,
                elementBuffer elementBuffer
        );

        vertexBuffer initializeVertexBuffer();

        vertexShader initializeVertexShader();

        fragmentShader initializeFragmentShader();

        shaderProgram initializeShaderProgram();

        void start();
    };
}

#endif //MYFIRSTOPENGL_OPENGL_H
