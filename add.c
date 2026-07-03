#include "student.h"

// Find Smallest Missing Roll
int missing_roll()
{
    STU *temp;
    int max_roll = 1;

    while(1)
    {
        temp = head;
        int found = 0;

        while(temp)
        {
            if(temp->roll == max_roll)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if(found==0)
            return max_roll;   

        max_roll++;
    }
}

void stud_add()
{
    STU *temp = (STU *)malloc(sizeof(STU));
    
    temp->roll = missing_roll();
    printf("Generated Roll No: %d\n", temp->roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", temp->name);

    printf("Enter Percentage: ");
    scanf("%f", &temp->per);

    temp->next = NULL;

    if(head == NULL)
    {
    	temp->next = NULL;
        head = temp;
    }
    else
    {
        STU *last = head;
        while(last->next)
            last = last->next;
	
    	temp->next = NULL;
        last->next = temp;
    }

    printf("Record Added Successfully.\n");
}

