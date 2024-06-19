#include<stdio.h>

int main()
{
    int num;

    printf("in:");
    scanf("%d", &num);

    if( 90 <= num)
    {
        printf("A");
    }

    if( 80 <= num)
    {
        printf("B");
    }

    if( 70 <= num)
    {
        printf("C");
    }

    if( 60 <= num)
    {
        printf("D");
    }
    
    else
    {
        printf("F");
    }
    

    return 0;
}