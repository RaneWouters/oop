#include <iostream>
#include <complex>
#include <vector>
#include <complex>
#include "Complex.h"
#include "Set.h"
using namespace std;

int main() {
    vector<Complex<double>> temp = {{1.0, 2.0}, {2.0, 3.0}, {0.5, 1.0}};
    Set<Complex<double>> set_user(temp);
//    Set<Complex<double>> set_temp(set_user);

//    set_user.insert({4.0, 5.0});
//    set_user.erase({1.0, 2.0});
//    cout << set_user << endl;
//    cout << set_temp << endl;

//    cout << set_user.common(set_temp);
//    cout << set_user.sum(set_temp);

//    cout << *set_user.find({4.0, 5.0}) << endl;
//    set_user.clear();

//    cout << set_user.number() << endl;

//    swap(set_user, set_temp);
//    cout << set_user << endl;
//    cout << set_temp << endl;

    return 0;
}
