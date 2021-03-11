#include <iostream>
using namespace std;

template <typename T>
T& Swap(T& lhs, T& rhs) {
    T c = lhs;
    lhs = rhs;
    rhs = c;
    cout << lhs << ' ' << rhs << endl;
    return lhs;
}

int main() {
    double i, j;
    string s1, s2;
    cout << "Please input two values:" << endl;
    cin >> i >> j;
    Swap(i, j);
    cout << "Please input two string:" << endl;
    cin >> s1 >> s2;
    Swap(s1, s2);
    return 0;
    
}
