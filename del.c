#include "student.h"

void delete_by_roll(int roll)
{
    STU *temp=head;
    STU *prev=NULL;
    while(temp)
    {
        if(temp->roll == roll)
        {
            if(prev) 
	    	prev->next = temp->next;
            else 
	    	head = temp->next;

            free(temp);
            printf("Record Deleted.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Roll No Not Found.\n");
}

void delete_by_name(char *name)
{
    STU *temp=head;
    int found = 0;
    printf("\nMatching Records:\n");
    while(temp)
    {
        if(strcmp(temp->name, name)==0)
        {
            printf("Roll: %d  Name: %s  Per: %.2f\n", temp->roll, temp->name, temp->per);
            found = 1;
        }
        temp = temp->next;
    }

    if(found==0)
    {
        printf("No matching name found.\n");
        return;
    }

    int r;
    printf("Enter Roll No to delete: ");
    scanf("%d",&r);
    delete_by_roll(r);
}

void stud_del()
{
    char ch;
    printf("\n=======================================\n");
    printf("| R/r : Enter Roll No to Delete       |\n");
    printf("| N/n : Enter Name to Delete          |\n");
    printf("=======================================\n");
 
    printf("Enter Your Choice: ");
    scanf(" %c",&ch);

    if(ch=='R' || ch=='r')
    {
        int r;
        printf("Enter Roll No: ");
        scanf("%d",&r);
        delete_by_roll(r);
    }
    if(ch=='N' || ch=='n')
    {
        char name[30];
        printf("Enter Name: ");
        scanf(" %[^\n]", name);
        delete_by_name(name);
    }
}

