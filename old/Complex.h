#include <iostream>
using namespace std;
class Complex {
   public:
    Complex() = default;
    Complex(double, double);
    Complex(const Complex&);
    ~Complex() {}

    double real() { return m_real; }
    double imag() { return m_imag; }
    void set(double, double);
    friend ostream& operator<<(ostream&, const Complex&);
    friend Complex operator+(const Complex&, const Complex&);
    friend Complex operator-(const Complex&, const Complex&);
    friend Complex operator*(const Complex&, const Complex&);
    friend Complex operator/(const Complex&, const Complex&);
    void operator=(const Complex&);
    bool operator==(const Complex&);
    bool operator!=(const Complex&);

   private:
    double m_real;
    double m_imag;
};
