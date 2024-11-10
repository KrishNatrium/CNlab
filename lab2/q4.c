/*
Write a c program to input a number and store the number across the following structure
and print the contents of each member of the structure.
Aggregate each member of the structure to form the original number and give the same.

 int a= 1
struct pkt
{char ch1;
char ch2[2];
char ch3;
}
*/

#include <stdio.h>

struct pkt
{
    char ch1;
    char ch2[2];
    char ch3;
};

int main()
{
    int num;
    struct pkt packet;

    printf("Enter a 4-byte integer: ");
    scanf("%d", &num);

    packet.ch1 = num & 0xFF;
    packet.ch2[0] = (num >> 8) & 0xFF;
    packet.ch2[1] = (num >> 16) & 0xFF;
    packet.ch3 = (num >> 24) & 0xFF;

    printf("ch1: %d\n", packet.ch1);
    printf("ch2[0]: %d\n", packet.ch2[0]);
    printf("ch2[1]: %d\n", packet.ch2[1]);
    printf("ch3: %d\n", packet.ch3);

    int original_num = (unsigned char)packet.ch1 |
                       ((unsigned char)packet.ch2[0] << 8) |
                       ((unsigned char)packet.ch2[1] << 16) |
                       ((unsigned char)packet.ch3 << 24);

    printf("Original number: %d\n", original_num);

    return 0;
}
