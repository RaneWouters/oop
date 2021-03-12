#include "MyVector.h"
using namespace std;

int main() {
    MyVector<int, 1000> vec = {1, 3, 6, 9, 19, 2, 3};
    //    cout << vec.size() << endl;
    //    cout << vec[1] << endl;
    //    try {
    //        cout << vec.at(3) << endl;
    //    } catch (int) {
    //        cout << "out of range!" << endl;
    //    }
    //    cout << vec.front() << endl;
    //    cout << vec.back() << endl;
    //    cout << endl;
    //
    //    vec.insert(2, 12);
    //    try {
    //        cout << vec.erase(3) << endl;
    //        cout << vec.erase(2) << endl;
    //        cout << vec.size() << endl;
    //    } catch (int) {
    //        cout << "can not erase!" << endl;
    //    }
    //    vec.clear();
    //    cout << vec.size() << endl;
    //    cout << vec[0] << endl;

    vec.show();
    vec.QuickSort(0, vec.size() - 1);
    vec.show();

    return 0;
}
