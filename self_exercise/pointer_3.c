#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10

int Print(int arr[],int n)
{
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

int GetRandNum(int arr[],int n)
{
    srand(time(NULL));

    for(int i = 0; i < N; i++)
    {
        arr[i] = rand() % 100 + 1;
    }

    return 0;
}

int swap(int *input_1, int *input_2)
{
    int temp = 0;
    temp = *input_1;
    *input_1= *input_2;
    *input_2 = temp;
    return 0;
}

int Bubblesrt(int arr[],int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i] < arr[j])
            {
                swap(&arr[i],&arr[j]);
            }
            else
            {
            }
        }
    }

    return 0;
}

int main()
{
    int numArr[N] = {0,};

    GetRandNum(numArr,N);
    
    printf("Before: ");
    Print(numArr,N);
    Bubblesrt(numArr,N);

    printf("\nAfter: ");
    Print(numArr, N);

    return 0;
}