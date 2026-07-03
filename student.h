#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int roll;
    char name[30];
    float per;
    struct student *next;
}STU;
STU *head;

void stud_add();
void stud_del();
void stud_show();
void stud_mod();
void stud_save();
void load_from_file();
void delete_all();
void reverse_list(STU *);
void sort_by_name();
void sort_by_percentage();

