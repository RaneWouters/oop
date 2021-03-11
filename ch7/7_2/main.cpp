#include <iostream>
#include "Set.h"
using namespace std;

int main() {
    int temp;
    Set<int> set_user;

    cin >> temp;
    while (temp != 0) {
        set_user.insert(temp);
        cin >> temp;
    }
    cout << *set_user.find(2) << endl;
}
