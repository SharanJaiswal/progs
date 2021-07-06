// single character number as operand, with valid expression shall be input
// postfix will get evaluated because whole infix to postfix to evaluation is of order O(n).
#include <stdio.h>
#include <stdlib.h>
#define MAX_EXP_SIZE 20

int arr1_itr = -1, arr2_itr = -1;

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

void push(char *arr, char a, int *itr)
{
    arr[++*itr] = a;
}

void transfer(char *arr1, int *itr1, char *arr2, int *itr2) // transfering a character from arr1 to arr2
{
    push(arr2, arr1[*itr1], itr2);
    --*itr1;
}

int operation(char operator, int operand2, int operand1)
{
    switch (operator)
    {
        case '*': return operand1*operand2;
        case '/': return operand1/operand2;
        case '%': return operand1%operand2;
        case '+': return operand1+operand2;
        case '-': return operand1-operand2;
    }
}

void push_int(int *arr, int a, int *itr)
{
    arr[++*itr] = a;
}

int pop(int *arr, int *itr)
{
    --*itr;
    return arr[*itr + 1];
}

int main()
{
    #include "../fileio.h"
    // arr1 will hold operators like in infix to postfix. arr2 will hold postfix expression
    // arr1 will hold operands and gets evaluated everytime an operator encounters from arr2. Result is pushed back
    char *arr1 = (char *)calloc(MAX_EXP_SIZE, sizeof(char)), *arr2 = (char *)calloc(MAX_EXP_SIZE, sizeof(char)), a;
    while((a = getchar()) != EOF)
    {
        if(a >= '0' && a <= '9')
        {
            push(arr2, a, &arr2_itr);
        }
        else if(a == ')')
        {
            while(arr1[arr1_itr] != '(' && arr1_itr > -1)
            {
                transfer(arr1, &arr1_itr, arr2, &arr2_itr);
            }
            if(arr1_itr == -1)
            {
                printf("\nInvalid expression entered.");
                return 0;
            }
            else if(arr1[arr1_itr] == '(')
            {
                arr1_itr--;
            }
        }
        else if(arr1_itr == -1 || a == '(')
        {
            push(arr1, a, &arr1_itr);
        }
        else
        {
            if(priority(a) <= priority(arr1[arr1_itr]))
            {
                while (priority(a) <= priority(arr1[arr1_itr]))
                {
                    transfer(arr1, &arr1_itr, arr2, &arr2_itr);
                    if(arr1_itr == -1 || priority(a) > priority(arr1[arr1_itr]))
                    {
                        push(arr1, a, &arr1_itr);
                        break;
                    }
                }
            }
            else
            {
                push(arr1, a, &arr1_itr);
            }
        }
    }
    while(arr1_itr > -1)
    {
        transfer(arr1, &arr1_itr, arr2, &arr2_itr);
    }
    free(arr1);
    push(arr2, '\0', &arr2_itr);
    arr2_itr = -1;

    int *arr = (int *)calloc(MAX_EXP_SIZE, sizeof(int));
    while(a = arr2[++arr2_itr])
    {
        if(a >= '0' && a <= '9')
        {
            push_int(arr, a-'0', &arr1_itr);
        }
        else
        {
            push_int(arr, operation(a, pop(arr, &arr1_itr), pop(arr, &arr1_itr)), &arr1_itr);
        }
    }
    printf("%d", arr[arr1_itr]);
    return 0;
}