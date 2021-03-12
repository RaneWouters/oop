#include "Complex.h"

Complex::Complex(double real, double imag) : m_real(real), m_imag(imag) {}
Complex::Complex(const Complex& obj) : m_real(obj.m_real), m_imag(obj.m_imag) {}

void Complex::set(double real, double imag) {
    this->m_real = real;
    this->m_imag = imag;
}
ostream& operator<<(ostream& os, const Complex& rhs) {
    os << "m_real = " << rhs.m_real << endl;
    os << "m_imag = " << rhs.m_imag << endl;
    return os;
};
Complex operator+(const Complex& a, const Complex& b) {
    Complex Complex;
    Complex.m_real = a.m_real + b.m_real;
    Complex.m_imag = a.m_imag + b.m_imag;
    return Complex;
}
Complex operator-(const Complex& a, const Complex& b) {
    Complex Complex;
    Complex.m_real = a.m_real - b.m_real;
    Complex.m_imag = a.m_imag - b.m_imag;
    return Complex;
}
Complex operator*(const Complex& a, const Complex& b) {
    Complex Complex;
    Complex.m_real = a.m_real * b.m_real - a.m_imag * b.m_imag;
    Complex.m_imag = a.m_real * b.m_imag + a.m_imag * b.m_real;
    return Complex;
}
Complex operator/(const Complex& a, const Complex& b) {
    Complex Com;
    Com.m_real = a.m_real * b.m_real + a.m_imag * b.m_imag;
    Com.m_real /= (a.m_imag * a.m_imag + b.m_imag * b.m_imag);
    Com.m_imag = a.m_imag * b.m_real - a.m_real * b.m_imag;
    Com.m_imag /= (a.m_imag * a.m_imag + b.m_imag * b.m_imag);
    return Com;
}
void Complex::operator=(const Complex& a) {
    this->m_real = a.m_real;
    this->m_imag = a.m_imag;
}
bool Complex::operator==(const Complex& a) {
    if (this->m_real == a.m_real && this->m_imag == a.m_imag)
        return 1;
    return 0;
}
bool Complex::operator!=(const Complex& a) {
    if (this->m_real == a.m_real && this->m_imag == a.m_imag)
        return 0;
    return 1;
}

