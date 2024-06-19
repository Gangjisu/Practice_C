#include <stdio.h>

int main()
{
    //00000000 00000000 00000000 00000001
    int number = 0;
    int interger_bitsize = (sizeof(int) * 8);
    unsigned int compare_num = 1 << (interger_bitsize - 1); 

    printf("input:");
    scanf("%d", &number); //2^32 4294967296이 최대
        
    
    for(int i = 0; i < interger_bitsize; i++)
    {
        printf("%d",(number & compare_num) ? 1 : 0);
        compare_num = compare_num >> 1;
    }

    return 0;
}

/* 해설
interger number를 받는다.

정수 1를 선언하여 정수의 가장 왼쪽 자릿수에 위치 시킨다.
1을 >>으로 왼쪽으로 한칸씩 이동하며 number의 같은 자릿수에 1과 같은 숫자가 있을 때 1을 출력하고 아닐때 0을 출력한다.

삼항 연산자를 사용하지않는다면 10진수로 출력된다.

추가적으로 2진수로 저장하려면 배열이 필요할 듯 싶다.

int number = 0;
    unsigned int mask = 1 << (sizeof(int) * 8 - 1);

    printf("Enter an integer: ");
    scanf("%d", &number); // 사용자로부터 정수 입력 받기

    for(int i = 1; i < 32; i++)
    {
        mask = mask >> 1;
        printf("%d", (mask & number) ? 1 : 0);
    }
    
*/