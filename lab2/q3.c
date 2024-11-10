/*
Write a c program to extract each byte from a given integer number and store them in separate character variables
and print the contents of those variables.
*/

#include <stdio.h>

struct Info
{
    int number;
};

int main()
{
    struct Info info;
    char b1, b2, b3, b0;

    printf("Enter an integer:");
    scanf("%d", &info.number);

    b0 = (info.number >> 0) & 0xFF;
    b1 = (info.number >> 8) & 0xFF;
    b2 = (info.number >> 16) & 0xFF;
    b3 = (info.number >> 24) & 0xFF;

    printf("Byte 0:%d\n", b0);
    printf("Byte 1:%d\n", b1);
    printf("Byte 2:%d\n", b2);
    printf("Byte 3:%d\n", b3);

    return 0;
}