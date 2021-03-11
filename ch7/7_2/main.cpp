#include <iostream>
#include <vector>
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
//    set_user.clear();

    vector<int>::iterator it = set_user.find(2);
    if(it != vector<int>::iterator(0)){
        cout << *it << endl;
    }
    return 0;
}
