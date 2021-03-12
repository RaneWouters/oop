#include <iostream>
#include <vector>
#include <complex>
#include "Set.h"
using namespace std;

int main() {
    vector<complex<double>> temp = {(1.0, 2.0), (2.0, 3.0), (0.5, 1.0)};
    Set<complex<double>> set_user(temp);
    cout << real(temp.at(0)) << endl;
    temp.at(1) = temp.at(2);
    cout << real(temp.at(1)) << endl;
    cout << real(temp.at(2)) << endl;

    return 0;
}
