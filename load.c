#include "student.h"

void load_from_file()
{
    FILE *fp = fopen("student.txt", "r");
    if(!fp)
    {
        printf("No saved file found!\n");
        return;
    }

    STU *temp, *last = NULL;
    head = NULL;

    int roll;
    char name[50];
    float per;

    while(fscanf(fp, "%d %s %f", &roll, name, &per) == 3)
    {
        temp = (STU *)malloc(sizeof(STU));
        temp->roll = roll;
        strcpy(temp->name, name);
        temp->per = per;
        temp->next = NULL;

        if(head == NULL)
            head = temp;
        else
            last->next = temp;

        last = temp;
    }

    fclose(fp);
    printf("Data Loaded from student.txt\n");
}

