#include <stdio.h>
#include <stdbool.h>

/**
 * print out the bytes of a variable, given its length
 */
void show_bytes(unsigned char *ptr, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("%#x ", *(ptr + i));
    }
    printf("\n");
}

/**
 * judge if the current machine is little endian
 */
bool is_little_endian()
{
    int a = 0x1;
    char *ptr = (char *)&a;
    return (*ptr == 0x1);
}

/**
 * concatenate 2 word
 */
int concat(int x, int y)
{
    int mask1 = 0xff;
    int mask2 = (~0) - 0xff;
    int result = (x & mask1) | (y & mask2);
    return result;
}

/**
 * replace the ith byte in x to b
 */
unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    unsigned mask1 = (~0) - (0xff << (i * 8));
    return (x & mask1) | (b << (i * 8));
}

/**
 * generate 1 if all bits of x == 1
 */
int gen_if_all_one(int x)
{
    return x == ~0;
}

/**
 * generate 1 if all bits of x == 0
 */
int gen_if_all_zero(int x)
{
    return x == 0;
}

int gen_if_least_byte_one(int x)
{
    return (x & 0xff) == 0xff;
}

int gen_if_least_byte_zero(int x)
{
    return ((0xff << 24) & x) >> 24 == 0;
}

int main(void)
{
    int a = 0x1;
    float f = __FLT_MAX__;
    double d = __DBL_MAX__;
    char *s = "Hello World!";

    show_bytes((unsigned char *)&a, sizeof(int));
    printf("%d\n", is_little_endian());

    int x = 0x89ABCDEF;
    int y = 0x76543210;
    unsigned result = concat(x, y);
    show_bytes((unsigned char *)&result, sizeof(int));

    unsigned result1 = replace_byte(0x12345678, 0, 0XAB);
    show_bytes((unsigned char *)&result1, sizeof(unsigned int));

    // show_bytes((unsigned char *)&f, sizeof(float));
    // show_bytes((unsigned char *)&d, sizeof(double));
    // show_bytes((unsigned char *)&s, 14);
}