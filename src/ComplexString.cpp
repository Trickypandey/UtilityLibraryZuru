#include "../Includes/ComplexString.h"
#include <stdexcept>
#include <regex>


namespace Util {
    ComplexString::ComplexString(const int& realValue , const int& imagValue ) :real{ realValue }, imag{imagValue} {}
    ComplexString::ComplexString(const std::string& realValue , const std::string& imagValue ) {
        
        /*size_t i_pos = imagValue.find('i');
        if (i_pos == std::string::npos || imagValue.find('i', i_pos + 1) != std::string::npos) {
            throw std::invalid_argument("Invalid complex number format: 'i' is missing or occurs more than once");
        }
        std::string newimagValue = imagValue.substr(0, i_pos - 1);

        if (!std::regex_match(realValue, std::regex("-?\\d+"))) {
            throw std::invalid_argument("Invalid complex number format: Real part is not an integer");
        }
        if (!std::regex_match(newimagValue, std::regex("-?\\d+"))) {
            throw std::invalid_argument("Invalid complex number format: Real part is not an integer");
        }
        
        real = std::stoi(realValue);
        imag = std::stoi(newimagValue);

        
        if (imagValue.size() > i_pos + 1) {
            throw std::invalid_argument("Invalid complex number format: Unexpected characters after 'i'");
        }*/
        if ( realValue.find('i') != std::string::npos && imagValue.find('i') != std::string::npos && realValue.find('i') && imagValue.find('i'))
        {
            throw std::invalid_argument("Invalid complex number format: both real and imaginary part contain i");
        }
        else if(realValue.find('i') != std::string::npos  && realValue.find('i'))
        {
            parseComplexNumber(imagValue, realValue);
        }
        else if(imagValue.find('i') != std::string::npos && imagValue.find('i'))
        {
            parseComplexNumber(realValue, imagValue);
        }
        else
        {
            throw std::invalid_argument("Invalid ComplexString number format: both real and imaginary part not contain i");
        }

    }

    void ComplexString::parseComplexNumber(const std::string& realValue, const std::string& imagValue) {
        size_t i_pos = imagValue.find('i');
        if (i_pos == std::string::npos || imagValue.find('i', i_pos + 1) != std::string::npos) {
            throw std::invalid_argument("Invalid complex number format: 'i' is missing or occurs more than once");
        }

        std::string newimagValue = imagValue.substr(0, i_pos);

        if (!std::regex_match(realValue, std::regex("-?\\d+"))) {
            throw std::invalid_argument("Invalid complex number format: Real part is not an integer");
        }
        if (!std::regex_match(newimagValue, std::regex("-?\\d+"))) {
            throw std::invalid_argument("Invalid complex number format: Imaginary part is not an integer");
        }

        real = std::stoi(realValue);
        imag = std::stoi(newimagValue);

       /* if (!newimagValue.empty()) {
            throw std::invalid_argument("Invalid complex number format: Unexpected characters after 'i'");
        }*/
    }

    ComplexString::ComplexString(ComplexString&& other) noexcept : real{ other.real }, imag{ other.imag } {
        other.real = 0;
        other.imag = 0;
    }

    ComplexString& ComplexString::operator=(ComplexString&& other) noexcept {
        if (this != &other) {
            real = other.real;
            imag = other.imag;
            other.real = 0;
            other.imag = 0;
        }
        return *this;
    }

    ComplexString::ComplexString(const std::string& ComplexStringStr) {
        size_t i_pos = ComplexStringStr.find('i');
        if (i_pos != std::string::npos) { 
            
            if (ComplexStringStr.find('i', i_pos + 1) != std::string::npos) {
                throw std::invalid_argument("Invalid complex number format: 'i' occurs more than once");
            }

            
            real = 0;
            imag = std::stoi(ComplexStringStr.substr(0, i_pos));
        }
        else { 
            real = std::stoi(ComplexStringStr);
            imag = 0;
        }
    }
    ComplexString Util::operator+(const ComplexString& c1, const ComplexString& c2) {
        return ComplexString(c1.real + c2.real, c1.imag + c2.imag);
    }

    
    /*std::ostream& operator<<(std::ostream& stream, const Complex& complex) {
        stream << complex.real << " + " << complex.imag << "i";
        return stream;
    }
    std::ostream& operator<<(std::ostream& stream, const char* str) {
        stream << str;
        return stream;
    }*/
}
