#ifndef LEARN_OPENGL_WATCH_H
#define LEARN_OPENGL_WATCH_H


namespace gl_lib {

    class Watch {
    private:
        double currentFrame;
        double lastFrame;

    public:
        Watch();

        void startFrame();

        double getDelta() const;

        double getCurrent() const;
    };
}


#endif //LEARN_OPENGL_WATCH_H
