/*
    2024.03.21 thu 08:56
*/
#include <stdio.h>

int main()
{
    //00000000 00000000 00000000
    double num1 = -6.5;
    long long *number = &num1;
    
    for(int i = 63; i >= 0; i--)
    {
        printf("%lld", ((*number) >> i) & 1);
    }

    /*
    printf("%lld", ((*number) >> 63) & 1);
    printf("%lld", ((*number) >> 62) & 1);
    printf("%lld", ((*number) >> 61) & 1);
    printf("...");
    printf("%lld", ((*number) >> 7) & 1);
    printf("%lld", ((*number) >> 6) & 1);
    printf("%lld", ((*number) >> 5) & 1);
    printf("%lld", ((*number) >> 4) & 1);
    printf("%lld", ((*number) >> 3) & 1);
    printf("%lld", ((*number) >> 2) & 1);
    printf("%lld", ((*number) >> 1) & 1);
    printf("%lld", ((*number) >> 0) & 1);
    */

    return 0;
}
/*
    %는 모듈러스?\
    getchar가 문자(열)입력 전에도 선언되어야 한다.
    LSB
    MSB
    단정밀도 실수 : float
    배정밀도 실수 : double

    소수의 비트스트림 표현
    MSB는 부호 1bit 11bit 정수부 표현 52bit는 소수부 표현
    bais 상수?
*/