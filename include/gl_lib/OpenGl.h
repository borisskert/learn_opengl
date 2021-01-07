#ifndef LEARN_OPENGL_OPENGL_H
#define LEARN_OPENGL_OPENGL_H


#include <gl_lib/gl_lib.h>
#include <vector>
#include "RuntimeException.h"
#include "ShaderInitializationException.h"
#include "Drawable.h"
#include "Shader.h"
#include "OpenGlBuffer.h"
#include "ContextContainer.h"
#include "Camera.h"
#include "Watch.h"
#include "MouseInputAdapter.h"
#include "MousePosition.h"
#include "LightSource.h"
#include "Game.h"


namespace gl_lib {

    class OpenGl : public MouseInputHandler {
    private:
        unsigned int screenWidth;
        unsigned int screenHeight;

        Camera camera = Camera::create();
        Watch watch;

        MouseInputAdapter *mouseInputAdapter;
        MousePosition *mousePosition;

        float fieldOfView = 45.0f;

        ContextContainer createContext(const std::vector<Drawable *> &drawables);

        Game *game;

    public:
        explicit OpenGl(unsigned int screenWidthInPixels, unsigned int screenHeightInPixels,
                        Game *game
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

        void onMouseMove(GLFWwindow *window, double x, double y) override;

        void onMouseScroll(GLFWwindow *window, double x, double y) override;

        Context createLightContext() const;

        void updateViewProjection(Shader *);

        void prepareContexts(ContextContainer &contexts);

        void initializeContexts(ContextContainer &contexts);

        void draw(ContextContainer &contexts);
    };
}

#endif //LEARN_OPENGL_OPENGL_H
