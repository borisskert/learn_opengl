#ifndef LEARN_OPENGL_SHADER_H
#define LEARN_OPENGL_SHADER_H

#include "gl_lib.h"
#include <glm/glm.hpp>
#include <string>


namespace gl_lib {

    class Shader {
    private:
        shaderProgram programId;

    public:
        Shader(const char *vertexPath, const char *fragmentPath);

        void use() const;

        void setBool(const std::string &name, bool value) const;

        void setInt(const std::string &name, int value) const;

        void setFloat(const std::string &name, float value) const;

        void setMat4(const std::string &name, glm::mat4 value) const;
    };
}


#endif //LEARN_OPENGL_SHADER_H
