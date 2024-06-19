#include <stdio.h>

int main()
{
    int dan;

    printf("dan:");
    scanf("%d", &dan);

    for(int i = 1; i < 10; i++)
    {
        printf("\n%d x %d = %d", dan, i, dan*i);
    }

    return 0;
}