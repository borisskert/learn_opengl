#ifndef MYFIRSTOPENGL_SHADER_H
#define MYFIRSTOPENGL_SHADER_H


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Typedefs.h"


static std::string readFileContent(const char *filePath) {
    std::string fileContent;
    std::ifstream fileStream;

    fileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        fileStream.open(filePath);
        std::stringstream contentStream;
        contentStream << fileStream.rdbuf();
        fileStream.close();
        fileContent = contentStream.str();
    } catch (std::ifstream::failure e) {
        throw RuntimeException("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ");
    }

    return fileContent.c_str();
}


static unsigned int compileShader(const char *shaderSource, GLenum shaderType) {
    unsigned int compiledShader;
    compiledShader = glCreateShader(shaderType);

    glShaderSource(compiledShader, 1, &shaderSource, nullptr);
    glCompileShader(compiledShader);

    int success;
    glGetShaderiv(compiledShader, GL_COMPILE_STATUS, &success);

    char infoLog[512];
    if (!success) {
        glGetShaderInfoLog(compiledShader, 512, nullptr, infoLog);
        throw ShaderInitializationException("ERROR::SHADER::COMPILATION_FAILED", infoLog);
    }

    return compiledShader;
}


static shaderProgram initializeShaderProgram(vertexShader vertexShader, fragmentShader fragmentShader) {
    shaderProgram shaderProgram;
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    int success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    char infoLog[512];
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        throw ShaderInitializationException("ERROR::SHADER::PROGRAM::LINKING_FAILED", infoLog);
    }

    return shaderProgram;
}


class Shader {
private:
    shaderProgram programId;

public:
    Shader(const char *vertexPath, const char *fragmentPath) {
        std::string vertexCode = readFileContent(vertexPath);
        std::string fragmentCode = readFileContent(fragmentPath);

        vertexShader vertexShader = compileShader(vertexCode.c_str(), GL_VERTEX_SHADER);
        fragmentShader fragmentShader = compileShader(fragmentCode.c_str(), GL_FRAGMENT_SHADER);

        this->programId = initializeShaderProgram(vertexShader, fragmentShader);
    }

    void use() const {
        glUseProgram(programId);
    }

    void setBool(const std::string &name, bool value) const {
        glUniform1i(glGetUniformLocation(this->programId, name.c_str()), (int) value);
    }

    void setInt(const std::string &name, int value) const {
        glUniform1i(glGetUniformLocation(this->programId, name.c_str()), value);
    }

    void setFloat(const std::string &name, float value) const {
        glUniform1f(glGetUniformLocation(this->programId, name.c_str()), value);
    }
};


#endif //MYFIRSTOPENGL_SHADER_H
