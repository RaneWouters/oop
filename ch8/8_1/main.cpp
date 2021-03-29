#include <iostream>
#include <vector>
#include "MyVector.h"
using namespace std;

int main() {
    int temp[] = {1, 2, 3, 4};
    MyVector<int> vec_temp(temp, sizeof(temp) / sizeof(int));
    vec_temp.show();

    MyVector<int> vec_user(vec_temp);
    vec_user.show();

    MyVector<int> vec_user2;
    vec_user2 = vec_user;
    vec_user2.show();
    cout << vec_user2.size() << endl;
    cout << endl;
    cout << vec_user2.at(4) << endl;
    cout << vec_user2.size() << endl;
    return 0;
}
