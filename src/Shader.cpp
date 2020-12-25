#include <gl_lib/Shader.h>
#include <gl_lib/gl_lib.h>
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
};