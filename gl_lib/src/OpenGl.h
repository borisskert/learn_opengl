#ifndef MYFIRSTOPENGL_OPENGL_H
#define MYFIRSTOPENGL_OPENGL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "RuntimeException.h"
#include "ShaderInitializationException.h"
#include "Typedefs.h"
#include "Drawable.h"
#include "Shader.h"


namespace mygl {

    class OpenGl {
    private:
        unsigned int screenWidth;
        unsigned int screenHeight;
        std::vector<Drawable *> models;

    public:
        explicit OpenGl(
                unsigned int screenWidthInPixels,
                unsigned int screenHeightInPixels,
                std::vector<Drawable *> models
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

        void render();

        /**
         * render loop
         * @param window pointer to the window object
         */
        void runEngine(
                GLFWwindow *window
        );

        void start();
    };
}

#endif //MYFIRSTOPENGL_OPENGL_H
