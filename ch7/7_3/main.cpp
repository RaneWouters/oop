#include "MyVector.h"
using namespace std;

int main() {
    MyVector<int, 1000> vec = {1, 2, 3};
    cout << vec.size() << endl;
    cout << vec[1] << endl;
    cout << vec.at(1) << endl;
    cout << vec.front() << endl;
    cout << vec.back() << endl;
    return 0;
}
