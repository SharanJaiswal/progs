#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    int stud_id;
    int name_len;
    int struct_size;
    char name[];    // to avoid shallow copying
} student;

student *CreateStudent(student *s, char *name)
{
    static int id = 0;
    s = (student *)malloc(sizeof(*s) + sizeof(char) * strlen(name));
    s->name_len = strlen(name);
    s->stud_id = ++id;
    strcpy(s->name, name);
    s->struct_size = sizeof(*s) + sizeof(char) * strlen(name);
    return s;
}

void print_details(student *s)
{
    printf("ID: %d\nName: %s\nName Len: %d\nStruct Len: %d\n\n", s->stud_id, s->name, s->name_len, s->struct_size);
}

int main()
{
    #include "../fileio.h"
    student *s1, *s2;
    s1 = CreateStudent(s1, "Sharan");
    s2 = CreateStudent(s2, "Saint");
    print_details(s1);
    print_details(s2);
    return 0;
}