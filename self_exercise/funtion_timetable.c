#include <stdio.h>

void PrintGugudan(int myDan)
{
    for(int i = 1; i < 10; i++)
    {
        printf("%d x %d = %d\n", myDan,i,myDan * i);
    }
}

int main()
{
    int dan;

    while (1)
    {
        printf("input:");
        scanf("%d", &dan);
        if(!dan)
            break;
        PrintGugudan(dan);
    }
    
    return 0;
}