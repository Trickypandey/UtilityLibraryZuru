#include<iostream>
#include "../Includes/Complex.h"
#include "../Includes/Exception.h"
using namespace Util;

Complex::Complex(double x, double y) : m_real{ x }, m_imag{ y } {}

std::ostream& Util::operator<<(std::ostream& stream, const Complex& c) {
	stream << c.m_real << (c.m_imag >= 0 ? " + " : " - ") << (c.m_imag >= 0 ? (c.m_imag) : (c.m_imag * (-1))) << "i\n";
	return stream;
}

Complex Util::operator+(const Complex& c1, const Complex& c2) {
	return Complex{ c1.m_real + c2.m_real , c1.m_imag + c2.m_imag };
}

Complex Util::operator-(const Complex& c1, const Complex& c2) {
	return Complex{ c1.m_real - c2.m_real , c1.m_imag - c2.m_imag };
}

Complex Util::operator*(const Complex& c1, const Complex& c2) {
	double real = (c1.m_real * c2.m_real) - (c1.m_imag * c2.m_imag);
	double imag = (c1.m_real * c2.m_imag) + (c1.m_imag * c2.m_real);
	return Complex{ real , imag };
}

Complex Util::operator/(const Complex& c1, const Complex& c2) {

	double denometer = (c2.m_real * c2.m_real) + (c2.m_imag * c2.m_imag);
	if (denometer == 0) {
		throw MyException("Complex: Cannot Divide a number by zero!");
	}
	Complex ans = c1 * Complex{ c2.m_real , c2.m_imag * (-1) };
	ans.m_real /= denometer;
	ans.m_imag /= denometer;
	return ans;
}