#include <stdio.h>
#include <math.h>

int main()
{
    int number;
    int int_bitsize = ((sizeof(int) * 8) - 1);
    unsigned int mask = 0;

    //signed 시에 pow의 31승이 오버플로우
    //10000000 00000000 00000000 00111011
    //00000000 00000000 00000000 00000001
    printf("input:");
    scanf("%d", &number);

    for(int i = int_bitsize; i >= 0; i--){
        mask = (unsigned int)pow(2,i); //default double형식, 오버플로우 문제 발생, pow 앞 괄호에 int가 아닌 unsigned를 넣을 시 해결
        int k = number & mask;
        printf("%d", ((k) ? 1 : 0)); //삼항연산자를 이용해 출력.
    }
    printf("\n");
    /*
    for(int i = int_bitsize; i >= 0; i--){ 
        mask = (int)pow(2,i); //i = 31 일때 문제가 발생
        printf("%d", (number & mask) / mask); //자릿수에 맞는 2의 제곱수로 나눠어 출력
    }
    두개의 차이는 밑에는 10진수로 나누기 부호
    위에는 비트 연산 
    c99에서는 //주석, 배열 크기 자동할당,#pragma warning(disable:4996), 코드 중간에 변수 선언
    */

    return 0;
}
