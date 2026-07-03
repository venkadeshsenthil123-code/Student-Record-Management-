#include "student.h"

STU* find_by_roll(int roll)
{
    STU *temp = head;
    while (temp)
    {
        if (temp->roll == roll)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void stud_mod()
{
    char ch;
    printf("\n================ MODIFY RECORD ================\n");
    printf("| R/r : Search by Roll No                      |\n");
    printf("| N/n : Search by Name                         |\n");
    printf("================================================\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &ch);

    int roll;
    char name[30];
    float per;

    STU *rec = NULL;
  
    // SEARCH BY ROLL NUMBER

    if (ch == 'R' || ch == 'r')
    {
        printf("Enter Roll No: ");
        scanf("%d", &roll);

        rec = find_by_roll(roll);

        if (!rec)
        {
            printf("\nRecord Not Found!\n");
            return;
        }
    }

    // SEARCH BY NAME

    if (ch == 'N' || ch == 'n')
    {
        printf("Enter Name: ");
        scanf(" %[^\n]", name);

        printf("\n================ MATCHING RECORDS ================\n");
        printf("| %-8s | %-20s | %-10s |\n", "Roll No", "Name", "Percentage");
        printf("--------------------------------------------------\n");

        STU *temp = head;
        int found = 0;

        while (temp)
        {
            if (strcmp(temp->name, name) == 0)
            {
                printf("| %-8d | %-20s | %10.2f |\n",
                       temp->roll, temp->name, temp->per);
                found = 1;
            }
            temp = temp->next;
        }

        if (found==0)
        {
            printf("           NO RECORDS FOUND\n");
            printf("--------------------------------------------------\n");
            return;
        }

        printf("--------------------------------------------------\n");
        printf("Enter Roll No to Modify: ");
        scanf("%d", &roll);
        rec = find_by_roll(roll);
    }

    // INVALID ROLL / NOT FOUND

    if (!rec)
    {
        printf("\nInvalid Roll No.\n");
        return;
    }

    // MODIFY MENU

    printf("\n================ MODIFY OPTIONS =================\n");
    printf("| N/n : Modify Name                             |\n");
    printf("| P/p : Modify Percentage                       |\n");
    printf("=================================================\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &ch);

    if (ch == 'N' || ch == 'n')
    {
        printf("Enter New Name: ");
        scanf(" %[^\n]", rec->name);
    }
    if (ch == 'P' || ch == 'p')
    {
        printf("Enter New Percentage: ");
        scanf("%f", &rec->per);
    }

    printf("\nRecord Modified Successfully!\n");
}

