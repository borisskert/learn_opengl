#ifndef MYFIRSTOPENGL_OPENGL_H
#define MYFIRSTOPENGL_OPENGL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "RuntimeException.h"
#include "ShaderInitializationException.h"
#include "VertexModels.h"

typedef unsigned int vertexBuffer;
typedef unsigned int vertexArray;
typedef unsigned int vertexShader;
typedef unsigned int fragmentShader;
typedef unsigned int elementBuffer;
typedef unsigned int shaderProgram;


struct DrawableElement {
    vertexBuffer vb;
    vertexArray va;
    elementBuffer eb;
    ElementBufferObject ebo;
};


namespace mygl {

    class OpenGl {
    private:
        unsigned int screenWidth;
        unsigned int screenHeight;
        std::vector<ElementBufferObject> models;

    public:
        explicit OpenGl(
                unsigned int screenWidthInPixels,
                unsigned int screenHeightInPixels,
                std::vector<ElementBufferObject> models
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

        elementBuffer initializeElementBuffer(const ElementBufferObject &);

        void render();

        void draw(
                vertexArray,
                const ElementBufferObject &
        );

        /**
         * Create and bind vertex array
         * @param vertexBuffer
         * @return
         */
        vertexArray initializeVertexArray(vertexBuffer, const ElementBufferObject &);

        /**
         * render loop
         * @param window pointer to the window object
         */
        void runEngine(
                GLFWwindow *window
        );

        vertexBuffer initializeVertexBuffer();

        vertexShader initializeVertexShader();

        fragmentShader initializeFragmentShader();

        shaderProgram initializeShaderProgram();

        void start();

        DrawableElement toDrawable(const ElementBufferObject &);

        void updateGlobalColorOverTime(shaderProgram shaderProgram) const;
    };
}

#endif //MYFIRSTOPENGL_OPENGL_H
