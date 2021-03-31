#include <bits/c++config.h>
#include <cstddef>
#include <iostream>
using namespace std;

string* Init(char* temp) {
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
    cout << count << endl;
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
    for (int q = 0; q <= string_loc; ++q) {
        cout << middle[q] << endl;
    }
    return middle;
}
