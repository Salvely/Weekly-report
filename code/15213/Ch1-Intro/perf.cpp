#include <ctime>
#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;
void copyij(int src[1000][1000],
            int dst[1000][1000])
{
    int i, j;
    for (i = 0; i < 1000; i++)
        for (j = 0; j < 1000; j++)
            dst[i][j] = src[i][j];
}
void copyji(int src[1000][1000],
            int dst[1000][1000])
{
    int i, j;
    for (j = 0; j < 1000; j++)
        for (i = 0; i < 1000; i++)
            dst[i][j] = src[i][j];
}
int main(void)
{
    int src[1000][1000];
    int dst[1000][1000];
    clock_t clock1_start = clock();
    copyij(src, dst);
    clock_t clock1_end = clock();
    cout << "Duration of copyij: " << (clock1_end - clock1_start) << endl;
    clock_t clock2_start = clock();
    copyji(src, dst);
    clock_t clock2_end = clock();
    cout << "Duration of copyji: " << (clock2_end - clock2_start) << endl;
}