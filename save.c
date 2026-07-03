#include "student.h"

void stud_save()
{
    FILE *fp = fopen("student.txt", "w");
    if(!fp)
    {
        printf("File Not Found!\n");
        return;
    }
    STU *temp = head;
    while(temp)
    {
        fprintf(fp, "%d %s %f\n", temp->roll, temp->name, temp->per);
        temp = temp->next;
    }
    fclose(fp);
    printf("Data Saved to student.txt\n");
}

