/*
Write a program in c to create a structure candidate having data members as reg. no, name, address and dob where dob is
another structure having data members as date, month and year.
Now enter and display the details of the candidate using nested structure concept.
*/

#include <stdio.h>

struct DOB
{
    int date;
    int month;
    int year;
};

struct Candidate
{
    int reg_no;
    char name[50];
    char address[100];
    struct DOB dob;
};

void enterCandidateDetails(struct Candidate *c)
{
    printf("Enter registration number: ");
    scanf("%d", &c->reg_no);
    printf("Enter name: ");
    scanf(" %[^\n]", c->name);
    printf("Enter address: ");
    scanf(" %[^\n]", c->address);
    printf("Enter date of birth (DD MM YYYY): ");
    scanf("%d %d %d", &c->dob.date, &c->dob.month, &c->dob.year);
}

void displayCandidateDetails(struct Candidate c)
{
    printf("\nCandidate Details:\n");
    printf("Registration Number: %d\n", c.reg_no);
    printf("Name: %s\n", c.name);
    printf("Address: %s\n", c.address);
    printf("Date of Birth: %02d/%02d/%04d\n", c.dob.date, c.dob.month, c.dob.year);
}

int main()
{
    struct Candidate candidate;

    enterCandidateDetails(&candidate);
    displayCandidateDetails(candidate);

    return 0;
}