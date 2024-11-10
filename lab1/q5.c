/*
Write a program in c to write some contents [character values] to a text file and read the same.
*/

#include <stdio.h>

int main()
{
    FILE *fp;
    char input[100], output[100];

    fp = fopen("file.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);
    fputs(input, fp);

    fclose(fp);

    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    fgets(output, sizeof(output), fp);
    printf("Content read from file: %s", output);

    fclose(fp);

    return 0;
}