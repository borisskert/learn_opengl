#ifndef LEARN_OPENGL_LIGHTSOURCEID_H
#define LEARN_OPENGL_LIGHTSOURCEID_H

namespace gl_lib {
    class LightSourceId {
    private:
        static LightSourceId *instance;

        int latestId = -1;
        unsigned int count = 0;

        LightSourceId();

    public:
        int createNew();

        unsigned int getCount() const;

        static LightSourceId *getInstance();
    };
}


#endif //LEARN_OPENGL_LIGHTSOURCEID_H
