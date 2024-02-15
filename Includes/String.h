#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>
#include <memory>


namespace Util {
    class String {
    private:
        std::unique_ptr<char[]> m_Buffer;
        size_t m_Size;


    public:
        String(const char* string = "");
        String(const String& other);
        String& operator=(const String& other);
        String(String&& other) noexcept;
        String& operator=(String&& other) noexcept;
        ~String() = default;

        void append(const String& other);
        String operator+(const String& other);
        char& operator[](size_t index);
        const char* getBuffer() const;
        void append(int number);
        const char* getc_str() const { return m_Buffer.get(); }   
        friend std::ostream& operator<<(std::ostream& stream, const String& string);
    };
}

#endif