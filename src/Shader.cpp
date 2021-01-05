#include <gl_lib/Shader.h>
#include <gl_lib/gl_lib.h>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <algorithm>


namespace gl_lib {

    Shader::Shader() {
        this->programId = createShaderProgram();
    }


    bool contains(const std::vector<std::string> &strings, const std::string &s) {
        for (const std::string &item : strings) {
            if (item == s) {
                return true;
            }
        }

        return false;
    }


    void Shader::attachVertexShader(const char *path) {
        std::string vertexShaderCode = readFileContent(path);

        if (!contains(this->attachedVertexShaders, vertexShaderCode)) {
            this->attachedVertexShaders.push_back(vertexShaderCode);
        }
    }


    void Shader::attachFragmentShader(const char *path) {
        std::string fragmentShaderCode = readFileContent(path);

        if (!contains(this->attachedFragmentShaders, fragmentShaderCode)) {
            this->attachedFragmentShaders.push_back(fragmentShaderCode);
        }
    }


    void Shader::initialize() {
        std::vector<unsigned int> attachedShaders;

        for (const std::string &vertexShaderCode : this->attachedVertexShaders) {
            vertexShader vertexShaderId = compileVertexShader(vertexShaderCode.c_str());
            glAttachShader(programId, vertexShaderId);

            attachedShaders.push_back(vertexShaderId);
        }

        for (const std::string &fragmentShaderCode : this->attachedFragmentShaders) {
            fragmentShader fragmentShaderId = compileFragmentShader(fragmentShaderCode.c_str());
            glAttachShader(programId, fragmentShaderId);

            attachedShaders.push_back(fragmentShaderId);
        }

        initializeShaderProgram(programId);

        for (unsigned int attachedShaderId : attachedShaders) {
            glDeleteShader(attachedShaderId);
        }
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

    void Shader::setVec3(const std::string &name, const float &x, const float &y, const float &z) const {
        unsigned int uniformLocation = glGetUniformLocation(this->programId, name.c_str());
        glUniform3f(uniformLocation, x, y, z);
    }

    void Shader::setMat4(const std::string &name, const glm::mat4 &value) const {
        unsigned int uniformLocation = glGetUniformLocation(this->programId, name.c_str());
        glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(value));
    }
};
