#ifndef MYFIRSTOPENGL_RUNTIMEEXCEPTION_H
#define MYFIRSTOPENGL_RUNTIMEEXCEPTION_H

#include <string>
#include <utility>

class RuntimeException : public std::exception {
private:
    std::string message;

public:
    RuntimeException() : std::exception() {}

    explicit RuntimeException(std::string message)
            : std::exception(),
              message(std::move(message)) {}

    std::string getMessage() const {
        return this->message;
    }
};

#endif //MYFIRSTOPENGL_RUNTIMEEXCEPTION_H
