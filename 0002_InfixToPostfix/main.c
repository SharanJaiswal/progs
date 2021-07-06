// single character variable as operand, with valid expression shall be input
#include <stdio.h>
#include <stdbool.h>
#define MAX_EXP_SIZE 20

int itr = -1;

void push(char *arr, char a)
{
    arr[++itr] = a;
}

void pop(char *arr)
{
    printf("%c", arr[itr--]);
}

int priority(char a)
{
    switch (a)
    {
    case '*':
    case '/':
    case '%':
        return 2;
    case '+':
    case '-':
        return 1;
    case '(':
        return 0;
    }
}

int main()  // upper operator should strictly should be of top priority. NOT even of same priority
{
    #include "../fileio.h"
    char operator[MAX_EXP_SIZE] = {'\0'}, operand[MAX_EXP_SIZE] = {'\0'}, a;
    while((a = getchar()) != EOF)
    {
        if(a >= 'a' && a <= 'z')
        {
            printf("%c", a);
        }
        else if(a == ')')
        {
            while(operator[itr] != '(' && itr > -1)
            {
                pop(operator);
            }
            if(itr == -1)
            {
                printf("\nInvalid expression entered.");
                return 0;
            }
            else if(operator[itr] == '(')
            {
                itr--;
            }
        }
        else if(itr == -1 || a == '(')
        {
            push(operator, a);
        }
        else
        {
            if(priority(a) > priority(operator[itr]))   // existing same level operand should be popped dued to L->R associativity
            {
                push(operator, a);
            }
            else
            {
                while(priority(operator[itr]) >= priority(a))
                {
                    pop(operator);
                    if(itr == -1 || operator[itr] > priority(a))
                    {
                        push(operator, a);
                        break;
                    }
                }
            }
        }
    }
    while(itr != -1)
    {
        pop(operator);
    }
    return 0;
}