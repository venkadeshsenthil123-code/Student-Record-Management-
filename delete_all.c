#include "student.h"

void delete_all()
{
    STU *temp;
    while(head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("All Records Deleted.\n");
}

