#include "MyVector.h"
using namespace std;

int main() {
    MyVector<int, 1000> vec = {3, 6, 9, 19, 2, 3};
    cout << vec.size() << endl;
    cout << vec[1] << endl;
    try {
        cout << vec.at(3) << endl;
    } catch (int) {
        cout << "out of range!" << endl;
    }
    cout << vec.front() << endl;
    cout << vec.back() << endl;
    cout << endl;

    vec.insert(2, 12);
    try {
        cout << vec.erase(3) << endl;
        cout << vec.erase(2) << endl;
        cout << vec.size() << endl;
    } catch (int) {
        cout << "can not erase!" << endl;
    }
    vec.clear();
    cout << vec.size() << endl;
    cout << vec[0] << endl;

    MyVector<int, 1000> vec_temp = {3, 6, 9, 19, 2, 3};
    vec_temp.show();
    vec_temp.QuickSort(0, vec_temp.size() - 1);
    vec_temp.show();

    cout << vec_temp.binary_search(6) << endl;

    return 0;
}
