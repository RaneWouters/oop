#include <iostream>
#include <string>
#include "Calculater.h"
#include <queue>
#include <stack>
using namespace std;

int main() {
    char temp[100];
//    temp[0] = '1';
//    temp[1] = '2';
//    temp[2] = '+';
//    temp[3] = '(';
//    temp[4] = 'c';
//    temp[5] = 'o';
//    temp[6] = 's';
//    temp[7] = '(';
//    temp[8] = '2';
//    temp[9] = '*';
//    temp[10] = 'p';
//    temp[11] = 'i';
//    temp[12] = ')';
//    temp[13] = ')';

    cin >> temp;
    cout << Cal_RP(Init(temp)) << endl;

//    queue<int> temp;
//    temp.push(1);
//    temp.push(3);
//    temp.pop();

//    string* temp = new string[10]();
//    *temp = "cos";
//    *(temp + 1) = "tan";
//    *(temp + 2) = "sqrt";
//    cout << (*(temp + 1)->begin()) << endl;

//    cout << level(*(temp + 0)) << endl;
//    cout << level(*(temp + 1)) << endl;
//    cout << level(*(temp + 2)) << endl;

//    string temp = "cos";
//    string temp1 = "1234";
//    cout << temp << endl;
//    cout << stod(temp1) + 1 << endl;

//    stack<string> temp;
//    temp.push("123");
//    cout << temp.top() << endl;
//    temp.pop();
    return 0;
}
