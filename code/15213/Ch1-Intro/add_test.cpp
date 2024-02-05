#include <iostream>
using namespace std;
int main(void)
{
    cout << "(2 + 3) - 100000 = " << (2 + 3) - 100000 << endl;
    cout << "2 + (3 - 100000) = " << 2 + (3 - 100000) << endl;

    cout << "(1e20 + -1e20) + 3.14 = " << (1e20 + -1e20) + 3.14 << endl;
    cout << "1e20 + (-1e20 + 3.14) = " << 1e20 + (-1e20 + 3.14) << endl;
    return 0;
}