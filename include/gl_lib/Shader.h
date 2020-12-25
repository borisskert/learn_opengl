#ifndef MYFIRSTOPENGL_SHADER_H
#define MYFIRSTOPENGL_SHADER_H

#include "Typedefs.h"
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
    };
}


#endif //MYFIRSTOPENGL_SHADER_H
