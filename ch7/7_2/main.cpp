#include <iostream>
#include <vector>
#include "Complex.h"
#include "Set.h"
using namespace std;

int main() {
    vector<Complex<double>> temp1 = {{1.0, 2.0}, {2.0, 3.0}, {0.5, 1.0}};
    vector<Complex<double>> temp2 = {{2.0, 3.0}, {5.0, 1.0}, {3.0, 9.0}};
    Set<Complex<double>> set_user1(temp1);
    Set<Complex<double>> set_user2(temp2);
    cout << "set_user1: " << endl << set_user1 << endl;
    cout << "set_user2: " << endl << set_user2 << endl;

    set_user1.insert({4.0, 5.0});
    set_user1.erase({1.0, 2.0});
    cout << "set_user1: " << endl << set_user1 << endl;
    cout << "set_user2: " << endl << set_user2 << endl;

    cout << set_user1.is_elem({4.0, 5.0}) << endl;
    cout << set_user1.is_elem({1.0, 2.0}) << endl;

    cout << set_user1.common(set_user2) << endl;
    cout << set_user1.sum(set_user2) << endl;

    cout << *set_user1.find({4.0, 5.0}) << endl;
    set_user1.clear();
    cout << "set_user1: " << endl << set_user1 << endl;
    cout << "set_user2: " << endl << set_user2 << endl;
    cout << "set_user2 number is " << set_user2.number() << endl;
    
    swap(set_user1, set_user2);
    cout << "set_user1: " << endl << set_user1 << endl;
    cout << "set_user2: " << endl << set_user2 << endl;


    return 0;
}
