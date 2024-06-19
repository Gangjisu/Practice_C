#include <stdio.h>

int main()
{
    //Odd 홀수
    //Even 짝수
    int num_1;
    
    printf("값을 입력:");
    scanf("%d", &num_1);

    (num_1 % 2) ? printf("\nOdd Num") : printf("\nEven Num");

    return 0;
}