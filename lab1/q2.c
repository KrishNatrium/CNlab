/*
Write a program in c to create a structure employee having data members empid, empname, basis salary, da(12% of basic salary),
ta(10% of basic salary) . Gp-> bs+ da+ ta. Enter the basic information of employee and calculate da, ta and gp.
Then display all details of the employee using pointer to structure.
*/

#include <stdio.h>

struct Employee
{
    int empid;
    char empname[50];
    float bs;
    float da;
    float ta;
    float gp;
};

void inputEmployee(struct Employee *e)
{
    printf("Enter employee ID: ");
    scanf("%d", &e->empid);
    printf("Enter employee name: ");
    scanf("%s", e->empname);
    printf("Enter basic salary: ");
    scanf("%f", &e->bs);

    e->da = 0.12 * e->bs;
    e->ta = 0.10 * e->bs;
    e->gp = e->bs + e->da + e->ta;
}

void displayEmployee(struct Employee *e)
{
    printf("\nEmployee Details:\n");
    printf("Employee ID: %d\n", e->empid);
    printf("Employee Name: %s\n", e->empname);
    printf("Basic Salary: %.2f\n", e->bs);
    printf("DA (12%%): %.2f\n", e->da);
    printf("TA (10%%): %.2f\n", e->ta);
    printf("Gross Pay: %.2f\n", e->gp);
}

int main()
{
    struct Employee emp;

    inputEmployee(&emp);

    displayEmployee(&emp);

    return 0;
}