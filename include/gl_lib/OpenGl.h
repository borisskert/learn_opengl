#ifndef LEARN_OPENGL_OPENGL_H
#define LEARN_OPENGL_OPENGL_H


#include <gl_lib/gl_lib.h>
#include <vector>
#include "RuntimeException.h"
#include "ShaderInitializationException.h"
#include "Drawable.h"
#include "Shader.h"
#include "OpenGlBuffer.h"


namespace gl_lib {

    struct ModelContext {
        Drawable* drawable;
        Shader* shader;
        OpenGlBuffer* buffer;
    };

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

        void clear();

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

#endif //LEARN_OPENGL_OPENGL_H
