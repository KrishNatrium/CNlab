/*
Write a c program to check whether the host machine is in Little Endian or big Endian format.
Enter a number, print the content of each byte location and convert the Endianness of the same.
*/

#include <stdio.h>

void check()
{
    unsigned int x = 1;
    char c = (char)&x; // Fixed the type and cast

    if (*c)
    {
        printf("The system is Little Endian.\n");
    }
    else
    {
        printf("The system is Big Endian.\n");
    }
}

void print(unsigned int num)
{
    unsigned char BP = (unsigned char)&num; // Fixed pointer type

    printf("Byte representation:\n");
    for (int i = 0; i < sizeof(num); i++)
    {
        printf("Byte %d: 0x%02x\n", i, BP[i]);
    }
}

unsigned int convert(unsigned int num)
{
    unsigned int con = 0;
    unsigned char BP = (unsigned char)&num; // Fixed pointer type
    unsigned char CP = (unsigned char)&con; // Fixed pointer type

    for (int i = 0; i < sizeof(num); i++)
    {
        CP[i] = BP[sizeof(num) - 1 - i];
    }
    return con;
}

int main()
{
    unsigned int num;

    check();

    printf("Enter a number: ");
    scanf("%u", &num);

    print(num);

    unsigned int conNum = convert(num);
    printf("\nAfter converting the endianness:\n");
    print(conNum);

    return 0;
}