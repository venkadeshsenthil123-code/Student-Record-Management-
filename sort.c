#include "student.h"

// Copy address of Linked List to Array and return no of elements copied (Helper Function)

int list_to_array(STU *arr[])
{
    STU *temp = head;
    int n = 0;

    while(temp)
    {
        arr[n++] = temp;
        temp = temp->next;
    }
    return n;
}

// Print Sorted by Name (Ascending)

void sort_by_name()
{
    if (!head)
    {
        printf("\nList Empty!\n");
        return;
    }

    STU *arr[100];
    int n = list_to_array(arr);

    // Bubble sort by name (A → Z)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[i]->name, arr[j]->name) > 0)
            {	
                STU *t = arr[i];   
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }

    printf("\n============ SORTED BY NAME (A → Z) ============\n");
    printf("| %-8s | %-20s | %-10s |\n", "Roll No", "Name", "Percentage");
    printf("================================================\n");

    for (int i = 0; i < n; i++)
    {
        printf("| %-8d | %-20s | %10.2f |\n",
               arr[i]->roll, arr[i]->name, arr[i]->per);
    }

    printf("================================================\n");
}
void sort_by_percentage()
{
    if (!head)
    {
        printf("\nList Empty!\n");
        return;
    }

    STU *arr[100];
    int n = list_to_array(arr);

    // Bubble sort (Descending order)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i]->per < arr[j]->per)  // High → Low
            {
                STU *t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }

    printf("\n======= SORTED BY PERCENTAGE (High → Low) ======\n");
    printf("| %-8s | %-20s | %-10s |\n", "Roll No", "Name", "Percentage");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("| %-8d | %-20s | %10.2f |\n",
               arr[i]->roll, arr[i]->name, arr[i]->per);
    }

    printf("==================================================\n");
}

