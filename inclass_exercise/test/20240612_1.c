#include <stdio.h>

int main()
{
    //1 2 4 7 11 16
    //////////////// 시험
    //항목 간의 차이가 자연수
    //3개의 제어 변수를 도입
    // N 번째까지 회차를 증가시켜 저장할 변수
    // i 번째 항목 값을 저장하는 변수
    // 항목 사이의 증분 값을 저장할 변수
    int N;
    int Sum;

    while (1){

        printf("input N:");
        if(scanf("%d", &N) == EOF)
        {
            break;
        }

        for (int idx = 1, num = 0, interval = 0; idx <= N; idx++, interval++) {
            num += interval;
            Sum += num;

            (idx == 1) ? printf("%d", num) : printf("%+d", num);
        }

        printf("=%d \n", Sum);

        Sum = 0;
    }

    return  0;
}


