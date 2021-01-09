#include "gl_lib/LightSourceId.h"

using namespace gl_lib;

int LightSourceId::createNew() {
    latestId++;
    count++;

    return latestId;
}

LightSourceId *LightSourceId::instance;

LightSourceId *LightSourceId::getInstance() {
    if (LightSourceId::instance == nullptr) {
        LightSourceId::instance = new LightSourceId();
    }

    return LightSourceId::instance;
}

unsigned int LightSourceId::getCount() const {
    return count;
}

LightSourceId::LightSourceId() = default;
