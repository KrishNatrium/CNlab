/*
Write a s c program to assign values to each members of the following structure to a function using call by address mechanism
and print the values of each member of the structure within the function.

 struct info
{ int roll no;
 char name[20];
 float cgpa;
}
*/

#include <stdio.h>
#include <string.h>

struct info
{
    int roll_no;
    char name[20];
    float cgpa;
};

void values(struct info *student)
{
    printf("Enter Roll Number: ");
    scanf("%d", &student->roll_no);
    printf("Enter Name: ");
    scanf("%s", student->name);
    printf("Enter CGPA: ");
    scanf("%f", &student->cgpa);

    printf("\nValues inside the function:\n");
    printf("Roll No: %d\n", student->roll_no);
    printf("Name: %s\n", student->name);
    printf("CGPA: %.2f\n", student->cgpa);
}

int main()
{
    struct info student;
    values(&student);

    return 0;
}