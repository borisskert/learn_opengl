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

        void setBool(const std::string &name, const bool &value) const;

        void setInt(const std::string &name, const int &value) const;

        void setFloat(const std::string &name, const float &value) const;

        void setVec3(const std::string &name, const glm::vec3 &value) const;

        void setVec3(const std::string &name, const float &, const float &, const float &) const;

        void setMat4(const std::string &name, const glm::mat4 &value) const;
    };
}


#endif //LEARN_OPENGL_SHADER_H
