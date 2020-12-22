#ifndef MYFIRSTOPENGL_SHADERINITIALIZATIONEXCEPTION_H
#define MYFIRSTOPENGL_SHADERINITIALIZATIONEXCEPTION_H

#include <utility>

#include "RuntimeException.h"

class ShaderInitializationException : public RuntimeException {
private:
    std::string infoLog;

public:
    ShaderInitializationException() : RuntimeException() {}

    explicit ShaderInitializationException(const std::string &message)
            : RuntimeException(message) {}

    explicit ShaderInitializationException(std::string message, std::string infoLog)
            : RuntimeException(std::move(message)),
              infoLog(std::move(infoLog)) {}

    std::string getInfoLog() const {
        return this->infoLog;
    }
};


#endif //MYFIRSTOPENGL_SHADERINITIALIZATIONEXCEPTION_H