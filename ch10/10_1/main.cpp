#include <ios>
#include <iomanip>
#include <iostream>
using namespace std;

constexpr double PI = 3.141592653;

int main() {
    cout << oct << 300 << endl;
    cout << dec << 300 << endl;
    cout << hex << 300 << endl;

    cout << fixed << setprecision(6) << PI << endl;
    cout << fixed << setprecision(8) << PI << endl;
    cout << scientific << PI << endl;
    cout << fixed << PI << endl;

    return 0;
}
