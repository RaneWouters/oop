#include <iostream>
#include <vector>
#include "MyVector.h"
using namespace std;

int main() {
    int temp[] = {1, 2, 3, 4};
    MyVector<int> vec_temp(temp, sizeof(temp) / sizeof(int));
    MyVector<int> vec_user(vec_temp);

    vec_temp.insert(2, 20);
    vec_temp.insert(2, 30);
    vec_temp.erase(2);
    vec_temp.clear();

    vec_temp.show();
    cout << vec_temp.size() << endl;

    vec_user.show();

    MyVector<int> vec_user2;
    vec_user2 = vec_user;

    vec_user2.show();

    cout << vec_user2.size() << endl;

    cout << endl;

    cout << vec_user2.at(2) << endl;
    cout << vec_user2.size() << endl;
    cout << vec_user2.back() << endl;
    cout << vec_user2.front() << endl;
    return 0;
}
