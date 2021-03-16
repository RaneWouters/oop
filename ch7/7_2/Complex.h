#include <iostream>
using namespace std;

template <typename T>
class Complex {
   public:
    Complex(){};

    Complex(T& obj_real = T(), T& obj_imag = T())
        : m_real(obj_real), m_imag(obj_imag) {}
    Complex(const Complex&) = default;

   private:
    T m_real;
    T m_imag;
};

template <>
class Complex<double> {
   public:
    Complex(const double& obj_real = 0.0, const double& obj_imag = 0.0) {
        this->m_real = obj_real;
        this->m_imag = obj_imag;
    }
    Complex(const Complex&) = default;

    double real() { return this->m_real; }
    double imag() { return this->m_imag; }

    friend ostream& operator<<(ostream&, const Complex<double>&);
    friend Complex<double> operator+(const Complex<double>&,
                                     const Complex<double>&);
    friend Complex<double> operator-(const Complex<double>&,
                                     const Complex<double>&);
    friend Complex<double> operator*(const Complex<double>&,
                                     const Complex<double>&);
    friend Complex<double> operator/(const Complex<double>&,
                                     const Complex<double>&);
    void operator=(const Complex<double>&);
    bool operator==(const Complex<double>&);
    bool operator!=(const Complex<double>&);
    void set(const double&, const double&);

   private:
    double m_real;
    double m_imag;
};

ostream& operator<<(ostream& os, const Complex<double>& rhs) {
    os << rhs.m_real << "+" << rhs.m_imag << "i" << endl;
    return os;
}
Complex<double> operator+(const Complex<double>& a, const Complex<double>& b) {
    Complex<double> Complex;
    Complex.m_real = a.m_real + b.m_real;
    Complex.m_imag = a.m_imag + b.m_imag;
    return Complex;
}
Complex<double> operator-(const Complex<double>& a, const Complex<double>& b) {
    Complex<double> Complex;
    Complex.m_real = a.m_real - b.m_real;
    Complex.m_imag = a.m_imag - b.m_imag;
    return Complex;
}
Complex<double> operator*(const Complex<double>& a, const Complex<double>& b) {
    Complex<double> Complex;
    Complex.m_real = a.m_real * b.m_real - a.m_imag * b.m_imag;
    Complex.m_imag = a.m_real * b.m_imag + a.m_imag * b.m_real;
    return Complex;
}
Complex<double> operator/(const Complex<double>& a, const Complex<double>& b) {
    Complex<double> Com;
    Com.m_real = a.m_real * b.m_real + a.m_imag * b.m_imag;
    Com.m_real /= (a.m_imag * a.m_imag + b.m_imag * b.m_imag);
    Com.m_imag = a.m_imag * b.m_real - a.m_real * b.m_imag;
    Com.m_imag /= (a.m_imag * a.m_imag + b.m_imag * b.m_imag);
    return Com;
}
void Complex<double>::operator=(const Complex<double>& a) {
    this->m_real = a.m_real;
    this->m_imag = a.m_imag;
}
bool Complex<double>::operator==(const Complex<double>& a) {
    if (this->m_real == a.m_real && this->m_imag == a.m_imag)
        return 1;
    return 0;
}
bool Complex<double>::operator!=(const Complex<double>& a) {
    if (this->m_real == a.m_real && this->m_imag == a.m_imag)
        return 0;
    return 1;
}
void Complex<double>::set(const double& real, const double& imag) {
    this->m_real = real;
    this->m_imag = imag;
}
