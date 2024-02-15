#include "String.h"
using namespace Util;
class MyException : public std::exception {
private:
    String message;
public:
    MyException(const String& msg) : message(msg) {}

    virtual const char* what() const noexcept override {
        return message.getc_str();
    }
};