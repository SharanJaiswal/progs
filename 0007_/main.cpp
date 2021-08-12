#include <iostream>

void shuffle(int *arr, int n, int i)
{
    int val = -(i+1);

    i=arr[i]-1;

    while(arr[i] > 0)
    {
        int new_i = arr[i] - 1;
        arr[i] = val;

        val = -(i+1);
        i = new_i;
    }
}

void rearrange(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i]++;
    }

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > 0)
        shuffle(arr, n, i);
    }

    for(int i = 0; i < n; i++)
    {
        arr[i] = (-1)*arr[i] - 1;
    }
}

int main()
{
    #include "../fileio.h"
    int arr[] = {2,0,1,4,5,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);

    for(int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ", ";
    }
    return 0;
}