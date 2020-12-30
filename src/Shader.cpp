#include <gl_lib/Shader.h>
#include <gl_lib/gl_lib.h>
#include <glm/gtc/type_ptr.hpp>
#include <string>


namespace gl_lib {

    Shader::Shader(const char *vertexPath, const char *fragmentPath) {
        std::string vertexCode = readFileContent(vertexPath);
        std::string fragmentCode = readFileContent(fragmentPath);

        vertexShader vertexShader = compileVertexShader(vertexCode.c_str());
        fragmentShader fragmentShader = compileFragmentShader(fragmentCode.c_str());

        this->programId = initializeShaderProgram(vertexShader, fragmentShader);
    }

    void Shader::use() const {
        glUseProgram(programId);
    }

    void Shader::setBool(const std::string &name, const bool &value) const {
        glUniform1i(glGetUniformLocation(this->programId, name.c_str()), (int) value);
    }

    void Shader::setInt(const std::string &name, const int &value) const {
        glUniform1i(glGetUniformLocation(this->programId, name.c_str()), value);
    }

    void Shader::setFloat(const std::string &name, const float &value) const {
        glUniform1f(glGetUniformLocation(this->programId, name.c_str()), value);
    }

    void Shader::setVec3(const std::string &name, const glm::vec3 &value) const {
        unsigned int uniformLocation = glGetUniformLocation(this->programId, name.c_str());
        glUniform3fv(uniformLocation, 1, &value[0]);
    }

    void Shader::setVec3(const std::string &name, const float & x, const float & y, const float & z) const {
        unsigned int uniformLocation = glGetUniformLocation(this->programId, name.c_str());
        glUniform3f(uniformLocation, x, y, z);
    }

    void Shader::setMat4(const std::string &name, const glm::mat4 &value) const {
        unsigned int uniformLocation = glGetUniformLocation(this->programId, name.c_str());
        glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(value));
    }
};
