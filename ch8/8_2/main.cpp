#include <iostream>
#include <string>
#include "Calculater.h"
#include <queue>
#include <stack>
using namespace std;

int main() {
    char temp[100];
//    temp[0] = '3';
//    temp[1] = '-';
//    temp[2] = '2';
//    temp[3] = '*';
//    temp[4] = '4';
//    temp[5] = '+';
//    temp[6] = '(';
//    temp[7] = '6';
//    temp[8] = '-';
//    temp[9] = '1';
//    temp[10] = ')';
//    temp[11] = '/';
//    temp[12] = '2';
//    temp[13] = '+';
//    temp[14] = '5';

//    temp[0] = '(';
//    temp[1] = '6';
//    temp[2] = '-';
//    temp[3] = '1';
//    temp[4] = ')';
//    temp[5] = '/';
//    temp[6] = '2';
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
