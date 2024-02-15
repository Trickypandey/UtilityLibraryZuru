#ifndef COMPLEXSTRING_H
#define COMPLEXSTRING_H

#include <string>

namespace Util {
    class ComplexString {
    private:
        int real;
        int imag;
        void parseComplexNumber(const std::string& realValue, const std::string& imagValue);
    private:
        ComplexString(const int& realValue = 0, const int& imagValue = 0);
    public:
        ComplexString(const std::string& realValue = "0", const std::string& imagValue = "0");

        
        ComplexString(ComplexString&& other) noexcept;

        
        ComplexString& operator=(ComplexString&& other) noexcept;

        
        ComplexString(const std::string& ComplexStringStr);

        
        int getReal() const { return real; }

        
        void setReal(int realValue) { real = realValue; }

        
        int getImag() const { return imag; }

        
        void setImag(int imagValue) { imag = imagValue; }

        friend ComplexString operator+(const ComplexString& c1, const ComplexString& c2);
        //friend std::ostream& operator<<(std::ostream& stream, const ComplexString& string);

    };
}

#endif
