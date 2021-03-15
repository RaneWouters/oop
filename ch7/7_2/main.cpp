#include <iostream>
#include <complex>
#include <vector>
#include <complex>
#include "Complex.h"
#include "Set.h"
using namespace std;

int main() {
    vector<Complex<double>> temp = {(1.0, 2.0), (2.0, 3.0), (0.5, 1.0)};
    //vector<complex<double>> temp = {(1.0, 2.0), (2.0, 3.0), (0.5, 1.0)};
    Set<Complex<double>> set_user(temp);

    cout << set_user << endl;

    return 0;
}
