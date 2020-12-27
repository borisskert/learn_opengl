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

    void Shader::setBool(const std::string &name, bool value) const {
        glUniform1i(glGetUniformLocation(this->programId, name.c_str()), (int) value);
    }

    void Shader::setInt(const std::string &name, int value) const {
        glUniform1i(glGetUniformLocation(this->programId, name.c_str()), value);
    }

    void Shader::setFloat(const std::string &name, float value) const {
        glUniform1f(glGetUniformLocation(this->programId, name.c_str()), value);
    }

    void Shader::setMat4(const std::string &name, glm::mat4 value) const {
        unsigned int uniformLocation = glGetUniformLocation(this->programId, name.c_str());
        glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(value));
    }
};
