#ifndef LEARN_OPENGL_MYGAME_H
#define LEARN_OPENGL_MYGAME_H


#include <gl_lib/Game.h>
#include <gl_lib/PointLight.h>


class MyGame : public gl_lib::Game {
private:
    std::vector<gl_lib::Drawable *> objects;
    std::vector<gl_lib::LightSource *> lights;

    gl_lib::PointLight *movedLight;
    gl_lib::Camera *camera;
    const gl_lib::Watch *watch;

public:
    explicit MyGame(const std::string &assetsPath);

    std::vector<gl_lib::Drawable *> getObjects() override;

    std::vector<gl_lib::LightSource *> getLights() override;

    void initialize(const gl_lib::Watch *, gl_lib::Camera *) override;

    void processInput(GLFWwindow *window) override;

    void update() override;
};


#endif //LEARN_OPENGL_MYGAME_H
