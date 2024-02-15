#ifndef COMPLEX_H 
#define COMPLEX_H 
#include<iostream>
namespace Util {
	class Complex {
	private:
		double m_real;
		double m_imag;

	public:
		Complex(double x = 0, double y = 0);
		friend std::ostream& operator<<(std::ostream& stream, const Complex& c);
		friend Complex operator+(const Complex& c1, const Complex& c2);
		friend Complex operator-(const Complex& c1, const Complex& c2);
		friend Complex operator*(const Complex& c1, const Complex& c2);
		friend Complex operator/(const Complex& c1, const Complex& c2);
	};
}

#endif