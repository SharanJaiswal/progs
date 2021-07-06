#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

int itr = -1;

int char_code(char c)
{
    switch(c)
    {
        case '(' : return 1;
        case '[' : return 2;
        case '{' : return 3;
        case ')' : return -1;
        case ']' : return -2;
        case '}' : return -3;
        default : return 0; // another characters except brackets will be ignored
    }
}

int main()
{
    #include "../fileio.h"
    char *container = (char *)calloc(MAX_SIZE, sizeof(char)), c;
    int flag = 0;
    while((c = getchar()) != EOF)
    {
        int code = char_code(c);
        if(code)
        {
            if(code < 0)
            {
                if(itr == -1) { flag = 1; break; }
                if(code + char_code(container[itr]) != 0) { flag = 1; break; }
                // else remove its paired opener
                --itr;
            }
            else    // push opener of pair
            {
                container[++itr] = c;
            }
        }
    }
    printf((flag || (itr != -1)) ? "Illegal Expression.\n" : "Legal Expression.\n");
    return 0;
}