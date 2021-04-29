#include "finance.h"
#include <cstdlib>
#include <ctime>

int main() {
    srand((int)time(0));
    Person temp(100000);
    temp.addInvestment(Saving(50000));
    temp.addInvestment(Fund(50000));
    cout << temp.settle() << endl;
    return 0;
}
