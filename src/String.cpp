#include "../Includes/String.h"
#include "../Includes/Exception.h"
using namespace Util;
String::String(const char* string) : m_Size(strlen(string)) {
    m_Buffer = std::make_unique<char[]>(m_Size + 1);
    if (!m_Buffer)
    {
        throw MyException("Stirng: Bad memory allocartion");
    }
    memcpy(m_Buffer.get(), string, m_Size);
    m_Buffer[m_Size] = '\0';
}

String::String(const String& other) : m_Size(other.m_Size) {
    m_Buffer = std::make_unique<char[]>(m_Size + 1);
    memcpy(m_Buffer.get(), other.m_Buffer.get(), m_Size + 1);
}

String::String(String&& other) noexcept : m_Buffer(other.m_Buffer.get()), m_Size(other.m_Size) {
    other.m_Buffer = nullptr;
    other.m_Size = 0;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        
        m_Size = other.m_Size;
        m_Buffer = std::make_unique<char[]>(m_Size + 1);
        memcpy(m_Buffer.get(), other.m_Buffer.get(), m_Size + 1);
    }
    return *this;
}

String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        
        m_Buffer = std::move(other.m_Buffer);
        m_Size = other.m_Size;
        other.m_Buffer = nullptr;
        other.m_Size = 0;
    }
    return *this;
}


void String::append(const String& other) {
    if (other.m_Size != 0) {
        size_t newSize = m_Size + other.m_Size;
        std::unique_ptr<char[]> result = std::make_unique<char[]>(newSize + 1);
        memcpy(result.get(), m_Buffer.get(), m_Size);
        memcpy(result.get() + m_Size, other.m_Buffer.get(), other.m_Size + 1);

        m_Buffer = std::move(result);
        m_Size = newSize;
    }
}

String String::operator+(const String& other) {
    String result = *this;
    result.append(other);
    return result;
}

char& String::operator[](size_t index) {
    if (index >= m_Size) {
        //index %= m_Size;
        throw MyException("String:Index out of bound");
    }
    return m_Buffer[index];
}

const char* String::getBuffer() const {
    return m_Buffer.get();
}

std::ostream& Util::operator <<(std::ostream& stream, const String& string) {
    stream << string.getBuffer();
    return stream;
}
void String::append(int number) { 
    int length = 0;
    int temp = number;
    if (number == 0) {
        length = 1;
    }
    else {
        while (temp != 0) {
            length++;
            temp /= 10;
        }
    }
    char* result = new char[length + 1];

    for (int i = length - 1; i >= 0; --i) {
        result[i] = '0' + number % 10;
        number /= 10;
    }
    result[length] = '\0';
    this->append(result);
    delete[] result;
}

void String::clear() {
    m_Buffer.reset(); 
    m_Size = 0; 
}