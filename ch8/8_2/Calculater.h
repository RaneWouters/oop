#include <bits/c++config.h>
#include <math.h>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

const double PI = atan(1.0) * 4;

double level(const string& temp) {
    if ((temp == "tan") || (temp == "sqrt") || (temp == "cos") ||
        (temp == "sin"))
        return 3;
    if (temp == "^")
        return 2;
    if ((temp == "*") || (temp == "/") || (temp == "%"))
        return 1;
    if ((temp == "-"))
        return 0.5;
    if (temp == "+")
        return 0;
    return -1;
}

queue<string> Init(char* temp) {
    size_t loc = 0;
    size_t count = 0;
    while (*(temp + loc) != '\0') {
        if (*(temp + loc) == 's') {
            if ((*(temp + loc + 1) == 'i') && (*(temp + loc + 2) == 'n')) {
                loc += 3;
            } else if ((*(temp + loc + 1) == 'q') &&
                       (*(temp + loc + 2) == 'r') &&
                       (*(temp + loc + 3) == 't')) {
                loc += 4;
            } else {
                ++loc;
            }
        } else if (*(temp + loc) == 'c') {
            if ((*(temp + loc + 1) == 'o') && (*(temp + loc + 2) == 's')) {
                loc += 3;
            } else {
                ++loc;
            }
        } else if (*(temp + loc) == 't') {
            if ((*(temp + loc + 1) == 'a') && (*(temp + loc + 2) == 'n')) {
                loc += 3;
            } else {
                ++loc;
            }
        } else if (*(temp + loc) == 'p') {
            if (*(temp + loc + 1) == 'i') {
                loc += 2;
            } else {
                ++loc;
            }
        } else {
            if ((*(temp + loc) >= '0') && (*(temp + loc) <= '9')) {
                while ((*(temp + loc) >= '0') && (*(temp + loc) <= '9')) {
                    ++loc;
                }
            } else {
                ++loc;
            }
        }
        ++count;
    }
    //    cout << "count" << count << endl;
    string* middle = new string[count]();
    loc = 0;
    size_t string_loc = 0;
    while (*(temp + loc) != '\0') {
        if (*(temp + loc) == 's') {
            if ((*(temp + loc + 1) == 'i') && (*(temp + loc + 2) == 'n')) {
                loc += 3;
                *(middle + string_loc) = "sin";
                ++string_loc;
            } else if ((*(temp + loc + 1) == 'q') &&
                       (*(temp + loc + 2) == 'r') &&
                       (*(temp + loc + 3) == 't')) {
                loc += 4;
                *(middle + string_loc) = "sqrt";
                ++string_loc;
            } else {
                *(middle + string_loc) = *(temp + loc);
                ++string_loc;
                ++loc;
            }
        } else if (*(temp + loc) == 'c') {
            if ((*(temp + loc + 1) == 'o') && (*(temp + loc + 2) == 's')) {
                *(middle + string_loc) = "cos";
                ++string_loc;
                loc += 3;
            } else {
                *(middle + string_loc) = *(temp + loc);
                ++string_loc;
                ++loc;
            }
        } else if (*(temp + loc) == 't') {
            if ((*(temp + loc + 1) == 'a') && (*(temp + loc + 2) == 'n')) {
                *(middle + string_loc) = "tan";
                ++string_loc;
                loc += 3;
            } else {
                *(middle + string_loc) = *(temp + loc);
                ++string_loc;
                ++loc;
            }
        } else if (*(temp + loc) == 'p') {
            if (*(temp + loc + 1) == 'i') {
                *(middle + string_loc) = to_string(PI);
                ++string_loc;
                loc += 2;
            } else {
                *(middle + string_loc) = *(temp + loc);
                ++string_loc;
                ++loc;
            }
        } else {
            if ((*(temp + loc) >= '0') && (*(temp + loc) <= '9')) {
                while ((*(temp + loc) >= '0') && (*(temp + loc) <= '9')) {
                    *(middle + string_loc) += *(temp + loc);
                    ++loc;
                }
                ++string_loc;
            } else {
                *(middle + string_loc) = *(temp + loc);
                ++string_loc;
                ++loc;
            }
        }
    }
    for (int q = 0; q < string_loc; ++q) {
        cout << middle[q] << endl;
    }
    cout << "string_loc" << string_loc << endl;

    queue<string> RP;
    stack<string> RP_sign;
    for (int q = 0; q < string_loc; ++q) {
        //        cout << q << endl;
        if (*middle[q].begin() >= '0' && *middle[q].begin() <= '9') {
            RP.push(middle[q]);
        } else if (middle[q] == "(") {
            RP_sign.push(middle[q]);
        } else if (middle[q] == ")") {
            while (RP_sign.top() != "(") {
                RP.push(RP_sign.top());
                RP_sign.pop();
                //++q;
            }
            RP_sign.pop();
            cout << endl;
            cout << RP_sign.empty() << endl;
            cout << endl;
        } else {
            if (RP_sign.empty()) {
                RP_sign.push(middle[q]);
            } else {
                if (RP_sign.top() == "(") {
                    RP_sign.push(middle[q]);
                } else if (level(middle[q]) > level(RP_sign.top())) {
                    RP_sign.push(middle[q]);
                } else if (level(middle[q]) <= level(RP_sign.top())) {
                    while (!RP_sign.empty() && (level(middle[q]) < level(RP_sign.top()))) {
                        RP.push(RP_sign.top());
                        RP_sign.pop();
                    }
                    RP_sign.push(middle[q]);
                }
            }
        }
    }

    while (!RP_sign.empty()) {
        if (RP_sign.top() != "(") {
            RP.push(RP_sign.top());
        }
        RP_sign.pop();
    }
    queue<string> temp1 = RP;
    while (!temp1.empty()) {
        cout << temp1.front() << ' ';
        temp1.pop();
    }
    cout << endl;
    //    queue<string> temp1 = RP;
    //    while (!temp1.empty()) {
    //        cout << temp1.front() << ' ';
    //        temp1.pop();
    //    }
    //    cout << endl;

    return RP;
}

size_t cal_num(const string& temp) {
    if ((temp == "*") || (temp == "/") || (temp == "%") || (temp == "+") ||
        (temp == "-") || (temp == "^"))
        return 2;
    if ((temp == "tan") || (temp == "sqrt") || (temp == "cos") ||
        (temp == "sin"))
        return 1;
    return 0;
}

double Cal_RP(queue<string> RP) {
    stack<double> value;
    while (!RP.empty()) {
        if (*RP.front().begin() >= '0' && *RP.front().begin() <= '9') {
            value.push(stod(RP.front()));
            RP.pop();
        } else if (cal_num(RP.front()) == 2) {
            double rhs = value.top();
            value.pop();
            double lhs = value.top();
            value.pop();
            if (RP.front() == "+") {
                value.push(lhs + rhs);
                RP.pop();
            } else if (RP.front() == "-") {
                value.push(lhs - rhs);
                RP.pop();
            } else if (RP.front() == "*") {
                value.push(lhs * rhs);
                RP.pop();
            } else if (RP.front() == "/") {
                value.push(lhs / rhs);
                RP.pop();
            } else if (RP.front() == "%") {
                value.push((int)lhs % (int)rhs);
                RP.pop();
            } else if (RP.front() == "^") {
                value.push(pow(lhs, rhs));
                RP.pop();
            }
        } else if (cal_num(RP.front()) == 1) {
            double rhs = value.top();
            value.pop();
            if (RP.front() == "tan") {
                value.push(tan(rhs));
                RP.pop();
            } else if (RP.front() == "cos") {
                value.push(cos(rhs));
                RP.pop();
            } else if (RP.front() == "sin") {
                value.push(sin(rhs));
                RP.pop();
            } else if (RP.front() == "sqrt") {
                value.push(sqrt(rhs));
                RP.pop();
            }
        }
        if (RP.empty() && value.size() == 1) {
            break;
        }
    }
    return value.top();
}
