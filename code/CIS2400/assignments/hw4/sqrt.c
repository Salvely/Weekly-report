#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int square(int num) {
    int i = 1;
    while(i * i < num) {
        i++;
    }
    return i;
}

int parity(int num) {
    int count = 0;
    while (num != 0)
    {
        count += (num & 0x1);
        num = num >> 1;
    }
    return count;
}

void strcopy()
{
    char *r0 = "I love programming!";
    int len = 0;
    char *ptr = r0;
    while (*ptr != '\0')
    {
        len += 1;
        ptr += 1;
    }
    char* r1 = (char *)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        r1[i] = r0[i];
    }
    r1[len] = '\0';
    free(r1);
}

void reverse_array()
{
    int a[] = {0, 1, 2, 3, 4};
    int length = sizeof(a) / sizeof(int);
    for (int i = 0; i < length / 2; i++) {
        int temp = a[i];
        a[i] = a[length - 1 - i];
        a[length - 1 - i] = temp;
    }
    for (int i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(void)
{
    // printf("%d\n",square(12));
    // printf("%d\n",square(25));
    // printf("%d\n",square(26));

    // printf("%d\n",parity(2));
    // printf("%d\n",parity(1));
    // printf("%d\n",parity(12));
    // printf("%d\n",parity(255));

    strcopy();
    // reverse_array();
}