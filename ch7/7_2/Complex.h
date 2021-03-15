#include <iostream>
using namespace std;

template <typename T>
class Complex {
   public:
    Complex(){};

    Complex(T& obj_real = T(), T& obj_imag = T())
        : m_real(obj_real), m_imag(obj_imag) {}
    Complex(const Complex&) = default;

    T real() { return this.m_real; }
    T imag() { return this.m_imag; }

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

    friend ostream& operator<<(ostream& os, const Complex& rhs) {
        os << "m_real = " << rhs.m_real << endl;
        os << "m_imag = " << rhs.m_imag << endl;
        return os;
    };

   private:
    double m_real;
    double m_imag;
};

