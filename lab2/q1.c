/*
Write a c program to swap the contents of 2 variables using function with pointer arguments.
*/

#include <stdio.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x, y;

    printf("Enter the value of x:");
    scanf("%d", &x);

    printf("Enter the value of y:");
    scanf("%d", &y);

    printf("Before swapping: x= %d and y=%d\n", x, y);

    swap(&x, &y);

    printf("After swapping: x= %d and y=%d", x, y);

    return 0;
}