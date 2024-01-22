#include <iostream>
using namespace std;
int main(void)
{
    cout << "Test integer range: " << endl;
    cout << "The result of 40000 * 40000: " << 40000 * 40000 << endl;
    cout << "The result of 50000 * 50000: " << 50000 * 50000 << endl;
    cout << "INT32_MAX = " << INT32_MAX << endl;
    cout << "UINT32_MAX = " << UINT32_MAX << endl;
    cout << endl;

    cout << "Test float range: " << endl;
    cout << "The result of 40000.0 * 40000.0: " << 40000.0 * 40000.0 << endl;
    cout << "The result of 50000.0 * 50000.0: " << 50000.0 * 50000.0 << endl;
    cout << "The result of FLT_MAX * FLT_MAX: " << __FLT_MAX__ * __FLT_MAX__ << endl;
    cout << "FLOAT_MAX = " << __FLT_MAX__ << endl;
    cout << "DOUBLE_MAX = " << __DBL_MAX__ << endl;
    return 0;
}