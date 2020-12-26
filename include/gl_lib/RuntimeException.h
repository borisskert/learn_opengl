#ifndef LEARN_OPENGL_RUNTIMEEXCEPTION_H
#define LEARN_OPENGL_RUNTIMEEXCEPTION_H

#include <string>
#include <utility>


namespace gl_lib {

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
}


#endif //LEARN_OPENGL_RUNTIMEEXCEPTION_H
