#include <iostream>
using namespace std;
typedef struct
{
    int a[2];
    double d;
} struct_t;
double func(int i)
{
    struct_t s;
    s.d = 3.14;
    s.a[i] = 1073741824;
    return s.d;
}

int main(void)
{
    cout << "Size of struct_t: " << sizeof(struct_t) << endl;
    cout << func(0) << endl;
    cout << func(1) << endl;
    cout << func(2) << endl;
    cout << func(3) << endl;
    cout << func(4) << endl;
    cout << func(5) << endl;
    cout << func(6) << endl;
    return 0;
}